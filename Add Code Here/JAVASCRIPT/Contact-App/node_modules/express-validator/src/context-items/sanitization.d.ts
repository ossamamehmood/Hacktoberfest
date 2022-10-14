import { Context } from '../context';
import { CustomSanitizer, Meta, StandardSanitizer } from '../base';
import { ContextItem } from './context-item';
export declare class Sanitization implements ContextItem {
    private readonly sanitizer;
    private readonly custom;
    private readonly options;
    constructor(sanitizer: StandardSanitizer | CustomSanitizer, custom: boolean, options?: any[]);
    run(context: Context, value: any, meta: Meta): Promise<void>;
}
