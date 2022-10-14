import { Location, Request } from './base';
export declare type MatchedDataOptions = {
    includeOptionals: boolean;
    locations: Location[];
    onlyValidData: boolean;
};
export declare function matchedData(req: Request, options?: Partial<MatchedDataOptions>): Record<string, any>;
