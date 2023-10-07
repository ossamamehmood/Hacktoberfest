var compactObject = obj => JSON.parse(
        JSON.stringify(obj, (_, val) => {
            if(Array.isArray(val)) return val.filter(Boolean);
            if(val) return val;
        }),
    )


// /** Follow on Github : @utsxvrai  **/