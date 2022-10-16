import { ReadonlyContext } from './context';
export interface Request {
    [k: string]: any;
    body?: any;
    cookies?: Record<string, any>;
    headers?: Record<string, any>;
    params?: Record<string, any>;
    query?: Record<string, any>;
}
export declare type Middleware = (req: Request, res: any, next: (err?: any) => void) => void;
export declare type Location = 'body' | 'cookies' | 'headers' | 'params' | 'query';
export declare type Meta = {
    req: Request;
    location: Location;
    path: string;
};
export declare type CustomValidator = (input: any, meta: Meta) => any;
export declare type StandardValidator = (input: string, ...options: any[]) => boolean;
export declare type CustomSanitizer = (input: any, meta: Meta) => any;
export declare type StandardSanitizer = (input: string, ...options: any[]) => any;
export declare type DynamicMessageCreator = (value: any, meta: Meta) => any;
export interface FieldInstance {
    path: string;
    originalPath: string;
    location: Location;
    value: any;
    originalValue: any;
}
export declare type ValidationError = {
    param: '_error';
    msg: any;
    nestedErrors: ValidationError[];
    location?: undefined;
    value?: undefined;
} | {
    location: Location;
    param: string;
    value: any;
    msg: any;
    nestedErrors?: unknown[];
};
export declare const contextsKey = "express-validator#contexts";
export interface InternalRequest extends Request {
    [contextsKey]?: ReadonlyContext[];
}
export declare class ValidationHalt extends Error {
}
