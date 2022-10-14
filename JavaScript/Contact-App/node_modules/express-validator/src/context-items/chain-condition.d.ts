import { ValidationChain } from '../chain';
import { Meta } from '../base';
import { Context } from '../context';
import { ContextItem } from './context-item';
export declare class ChainCondition implements ContextItem {
    private readonly chain;
    constructor(chain: ValidationChain);
    run(_context: Context, _value: any, meta: Meta): Promise<void>;
}
