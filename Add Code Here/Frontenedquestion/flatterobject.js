const obj={
    a:"jatin",
    b:"ytash",
    c:{
        1:"hlio",
        2:"rti",
        3:{
            a:"jatin",
            b:"ytash"
        },
        4:[2,3]
    }
}
const ci= [
    [{"a": null}],
    [{"b": true}],
    [{"c": "x"}]
  ]
function flatterobjec(obj,peak=""){
    let objecti={}
 

    for(const key in obj){
        const val=obj[key];
        const newkey=peak==""?key:peak+"."+key;
        if(val!==null && typeof val==="object"){
        let recurcive=flatterobjec(val,newkey)
        objecti={...objecti,...recurcive}
    }
 
    else{
        objecti[newkey]=val;
    }
}
    return objecti;

}

console.log(flatterobjec(ci));