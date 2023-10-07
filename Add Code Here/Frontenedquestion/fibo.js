
const counter=function*(n){
     let a=[]
    if(n==0){
    a=[]
   }else{
for(let i=0;i<n;i++){
    if(i<=1){
        a.push(i);
    }
    else{
        let j=a[i-1]+a[i-2]
        a.push(j);
    }
    }
yield a;
}

}
const hlo=counter(5);
console.log(hlo.next().value);
