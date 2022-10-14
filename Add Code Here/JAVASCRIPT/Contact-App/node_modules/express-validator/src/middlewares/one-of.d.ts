import { ValidationChain } from '../chain';
import { Middleware, Request } from '../base';
export declare type OneOfCustomMessageBuilder = (options: {
    req: Request;
}) => any;
export declare function oneOf(chains: (ValidationChain | ValidationChain[])[], message?: OneOfCustomMessageBuilder): Middleware & {
    run: (req: Request) => Promise<void>;
};
export declare function oneOf(chains: (ValidationChain | ValidationChain[])[], message?: any): Middleware & {
    run: (req: Request) => Promise<void>;
};
