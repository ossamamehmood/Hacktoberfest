function hlo(arr){ 
    let setting=new Set();
 for(const obj of arr){
  flatt(obj,"")
 }
     function flatt(obj,peak=""){
      
       for(let key in obj){
        let newkey=peak==""?key:peak+"."+key
        if(obj[key]!=="" && typeof obj[key]=="object"){
            flatt(obj[key],newkey)
        }
       else{
        setting.add(newkey)
       }
    }
    
    
}
let sortdta=Array.from(setting).sort();
const res=[sortdta]
for(let obj1 of arr){
    const keytoval={};
   getvalue(obj1,path="",keytoval)
    let row=[];
    for(key of sortdta){
        if(key in keytoval){
            row.push(keytoval[key])
        }
        else{
            row.push("")
        }
    }
  res.push(row)
  console.log(keytoval)
}

function getvalue(obj,path="",keytoval){
   
    for(let key in obj){
        let newkey=path==""?key:path+"."+key
        if(obj[key]!=="" && typeof obj[key]=="object"){
            getvalue(obj[key],newkey,keytoval)
        }
        else{
            keytoval[newkey]=obj[key]
        }
    }
}

console.log(res)
}
//  obj=[
//   [{"a": null}],
//   [{"b": true}],
//   [{"c": "x"}]
// ]
obj = [
    {"b": 1, "a": 2},
    {"b": 3, "a": 4}
  ]
hlo(obj);