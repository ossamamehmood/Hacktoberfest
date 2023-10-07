const obj={
    a:{
        b:{
            c:"hii"        }
    }
}
function get(obj,hlo) {
    let objti={}
    let peak=""
    for(key in obj){
        const val = obj[key];
        const newkey=peak==""?key:peak +"."+key;
        if(val!==null && typeof val==="object"){
           let recurive= get(val,newkey);
           objti={...objti,...recurive}
        } 
        else{
           objti[newkey]=val;
        }

    }
    for(var key in objti){
        if(objti[key]==hlo){
         return objti[key];
        }
        else{
            console.log(hlo)
        }
    }

}
console.log(get(obj,"a.b.c"))
