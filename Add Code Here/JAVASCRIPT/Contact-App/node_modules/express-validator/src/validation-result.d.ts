import { Request, ValidationError } from './base';
export declare type ErrorFormatter<T = any> = (error: ValidationError) => T;
export declare type ResultFactory<T> = (req: Request) => Result<T>;
interface ResultFactoryBuilderOptions<T = any> {
    formatter: ErrorFormatter<T>;
}
export declare const validationResult: ResultFactory<ValidationError> & {
    withDefaults: typeof withDefaults;
};
export declare class Result<T = any> {
    private formatter;
    private readonly errors;
    constructor(formatter: ErrorFormatter<T>, errors: readonly ValidationError[]);
    array(options?: {
        onlyFirstError?: boolean;
    }): T[];
    mapped(): Record<string, T>;
    formatWith<T2>(formatter: ErrorFormatter<T2>): Result<T2>;
    isEmpty(): boolean;
    throw(): void;
}
declare function withDefaults<T = any>(options?: Partial<ResultFactoryBuilderOptions<T>>): ResultFactory<T>;
export {};
