"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.oneOf = void 0;
const _ = require("lodash");
const chain_1 = require("../chain");
const context_builder_1 = require("../context-builder");
// A dummy context item that gets added to surrogate contexts just to make them run
const dummyItem = { async run() { } };
function oneOf(chains, message) {
    const middleware = async (req, _res, next) => {
        const surrogateContext = new context_builder_1.ContextBuilder().addItem(dummyItem).build();
        // Run each group of chains in parallel, and within each group, run each chain in parallel too.
        const promises = chains.map(async (chain) => {
            const group = Array.isArray(chain) ? chain : [chain];
            const results = await Promise.all(group.map(chain => chain.run(req, { dryRun: true })));
            const contexts = results.map(result => result.context);
            const groupErrors = _.flatMap(contexts, 'errors');
            // #536: The data from a chain within oneOf() can only be made available to e.g. matchedData()
            // if its entire group is valid.
            if (!groupErrors.length) {
                contexts.forEach(context => {
                    surrogateContext.addFieldInstances(context.getData());
                });
            }
            return groupErrors;
        });
        try {
            const allErrors = await Promise.all(promises);
            const success = allErrors.some(groupErrors => groupErrors.length === 0);
            if (!success) {
                // Only add an error to the context if no group of chains had success.
                surrogateContext.addError(typeof message === 'function' ? message({ req }) : message || 'Invalid value(s)', _.flatMap(allErrors));
            }
            // Final context running pass to ensure contexts are added and values are modified properly
            await new chain_1.ContextRunnerImpl(surrogateContext).run(req);
            next();
        }
        catch (e) {
            next(e);
        }
    };
    const run = async (req) => {
        return new Promise((resolve, reject) => {
            middleware(req, {}, (e) => {
                e ? reject(e) : resolve();
            });
        });
    };
    return Object.assign(middleware, { run });
}
exports.oneOf = oneOf;
