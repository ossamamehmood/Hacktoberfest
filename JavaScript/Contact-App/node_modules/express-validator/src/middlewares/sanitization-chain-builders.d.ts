import { Location } from '../base';
export declare function buildSanitizeFunction(locations: Location[]): (fields?: string | string[] | undefined) => import("..").SanitizationChain;
export declare const sanitize: (fields?: string | string[] | undefined) => import("..").SanitizationChain;
export declare const sanitizeBody: (fields?: string | string[] | undefined) => import("..").SanitizationChain;
export declare const sanitizeCookie: (fields?: string | string[] | undefined) => import("..").SanitizationChain;
export declare const sanitizeParam: (fields?: string | string[] | undefined) => import("..").SanitizationChain;
export declare const sanitizeQuery: (fields?: string | string[] | undefined) => import("..").SanitizationChain;
