const arryi=[1,2,3,4,[5,7,8]]
function flatterarray(arrt){
  let arry=[];
  for(let i=0;i<arrt.length;i++){
    let  val=arrt[i];
    if(Array.isArray(val)){
        let recursive=flatterarray(val);
        arry=[...arry,...recursive]
  }
  else{
    arry.push(val);
  }
}
return arry;
}
console.log(flatterarray(arryi)); 