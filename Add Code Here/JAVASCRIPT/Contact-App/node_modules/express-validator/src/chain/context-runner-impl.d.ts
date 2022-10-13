import { Request } from '../base';
import { Context, ReadonlyContext } from '../context';
import { ContextBuilder } from '../context-builder';
import { SelectFields } from '../select-fields';
import { Result } from '../validation-result';
import { ContextRunner } from './context-runner';
declare class ResultWithContext extends Result {
    readonly context: ReadonlyContext;
    constructor(context: ReadonlyContext);
}
export declare class ContextRunnerImpl implements ContextRunner {
    private readonly builderOrContext;
    private readonly selectFields;
    constructor(builderOrContext: ContextBuilder | Context, selectFields?: SelectFields);
    run(req: Request, options?: {
        dryRun?: boolean;
    }): Promise<ResultWithContext>;
}
export {};
