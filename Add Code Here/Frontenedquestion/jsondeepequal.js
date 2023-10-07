const o1 = {"x":1,"y":2}
const  o2 = {"x":2,"y":2}
function jsonequal(o1,o2) {
    let k;
    for(let key in o1) {
        for(let val in o2) {
            if(key ===val && o1[key]===o2[val]) {
               
                k=true;
                break;
            }
            else{
               
               
            }
        }
    }
    return k
}
console.log(jsonequal(o1,o2))