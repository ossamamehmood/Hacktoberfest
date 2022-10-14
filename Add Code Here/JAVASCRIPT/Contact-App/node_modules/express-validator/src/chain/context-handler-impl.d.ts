import { ContextBuilder } from '../context-builder';
import { Optional } from '../context';
import { CustomValidator } from '../base';
import { ContextHandler } from './context-handler';
import { ValidationChain } from './validation-chain';
export declare class ContextHandlerImpl<Chain> implements ContextHandler<Chain> {
    private readonly builder;
    private readonly chain;
    constructor(builder: ContextBuilder, chain: Chain);
    bail(): Chain;
    if(condition: CustomValidator | ValidationChain): Chain;
    optional(options?: Optional | true): Chain;
}
