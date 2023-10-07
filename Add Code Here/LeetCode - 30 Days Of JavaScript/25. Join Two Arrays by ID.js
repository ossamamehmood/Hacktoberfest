var join = function(...arrs) {
    let map = new Map();
    for(let arr of arrs){
        for(let obj of arr){
            map.set(obj.id, {...map.get(obj.id), ...obj});
        }
    } 
   return [...map.values()].sort((lhs, rhs) => lhs.id - rhs.id);
};


/** Follow on Github : @utsxvrai  **/