const obj={
    a:{
     b: (a,b,c)=>a+b+c,
      c: (a,b,c)=>a+b-c,
     },
    e:(a,b,c)=>a-b-c,
  }
  function pipe(obj){
    return (...arg)=>{
      for(let key in obj){
        const value=obj[key]
        if(typeof obj[key]=="function"){
          obj[key]=value(...arg)
          
        }
        else{
         obj[key]=pipe(value)(...arg)
        }
      }
      return obj;
    }
  
  }
  console.log(pipe(obj)(1,1,1))
  
  