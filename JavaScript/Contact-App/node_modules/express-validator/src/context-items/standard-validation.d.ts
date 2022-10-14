import { Meta, StandardValidator } from '../base';
import { Context } from '../context';
import { ContextItem } from './context-item';
export declare class StandardValidation implements ContextItem {
    private readonly validator;
    private readonly negated;
    private readonly options;
    message: any;
    constructor(validator: StandardValidator, negated: boolean, options?: any[]);
    run(context: Context, value: any, meta: Meta): Promise<void>;
}
