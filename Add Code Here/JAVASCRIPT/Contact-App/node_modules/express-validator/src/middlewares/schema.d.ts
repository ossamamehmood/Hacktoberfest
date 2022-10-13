import { Sanitizers } from '../chain/sanitizers';
import { Validators } from '../chain/validators';
import { DynamicMessageCreator, Location, Request } from '../base';
import { ValidationChain } from '../chain';
import { Optional } from '../context';
declare type ValidatorSchemaOptions<K extends keyof Validators<any>> = true | {
    options?: Parameters<Validators<any>[K]> | Parameters<Validators<any>[K]>[0];
    errorMessage?: DynamicMessageCreator | any;
    negated?: boolean;
    bail?: boolean;
};
export declare type ValidatorsSchema = {
    [K in keyof Validators<any>]?: ValidatorSchemaOptions<K>;
};
declare type SanitizerSchemaOptions<K extends keyof Sanitizers<any>> = true | {
    options?: Parameters<Sanitizers<any>[K]> | Parameters<Sanitizers<any>[K]>[0];
};
export declare type SanitizersSchema = {
    [K in keyof Sanitizers<any>]?: SanitizerSchemaOptions<K>;
};
declare type InternalParamSchema = ValidatorsSchema & SanitizersSchema;
/**
 * Defines a schema of validations/sanitizations plus a general validation error message
 * and possible field locations.
 */
export declare type ParamSchema = InternalParamSchema & {
    in?: Location | Location[];
    errorMessage?: DynamicMessageCreator | any;
    optional?: true | {
        options?: Partial<Optional>;
    };
};
/**
 * @deprecated  Only here for v5 compatibility. Please use ParamSchema instead.
 */
export declare type ValidationParamSchema = ParamSchema;
/**
 * Defines a mapping from field name to a validations/sanitizations schema.
 */
export declare type Schema = Record<string, ParamSchema>;
/**
 * @deprecated  Only here for v5 compatibility. Please use Schema instead.
 */
export declare type ValidationSchema = Schema;
export declare function checkSchema(schema: Schema, defaultLocations?: Location[]): ValidationChain[] & {
    run: (req: Request) => Promise<unknown[]>;
};
export {};
