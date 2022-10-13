import { FieldInstance, Location, Request } from './base';
export declare type SelectFields = (req: Request, fields: string[], locations: Location[]) => FieldInstance[];
export declare const selectFields: SelectFields;
