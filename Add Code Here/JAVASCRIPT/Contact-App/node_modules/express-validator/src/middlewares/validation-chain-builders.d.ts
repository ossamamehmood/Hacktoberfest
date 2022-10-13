import { Location } from '../base';
export declare function buildCheckFunction(locations: Location[]): (fields?: string | string[] | undefined, message?: any) => import("..").ValidationChain;
export declare const check: (fields?: string | string[] | undefined, message?: any) => import("..").ValidationChain;
export declare const body: (fields?: string | string[] | undefined, message?: any) => import("..").ValidationChain;
export declare const cookie: (fields?: string | string[] | undefined, message?: any) => import("..").ValidationChain;
export declare const header: (fields?: string | string[] | undefined, message?: any) => import("..").ValidationChain;
export declare const param: (fields?: string | string[] | undefined, message?: any) => import("..").ValidationChain;
export declare const query: (fields?: string | string[] | undefined, message?: any) => import("..").ValidationChain;
