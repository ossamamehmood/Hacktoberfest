///first method bruteforce
// function sum(arr){
 
//     let sum=0
//     let hiio=arr.split("").map((item)=>Number(item))
//     for(let i=0;i<=hiio.length-1;i++){
//       sum=sum+hiio[i];
     
//     }
//    // let hio=su.reduce((acc,cuu)=>acc+cuu,0);
//     console.log(sum)
//   }
//   sum("123")



///second method
function recsum(num){
    num=Number(num)
   console.log(num)
     if(num==0){
         return 0;
     }
     return recsum(Math.floor(num/10))+num%10
 
 }
 console.log(recsum("1234"))
 // product of digit
 function recsum(num){
    num=Number(num)
 
     if(num==0){
         return 1;
     }
     return recsum(Math.floor(num/10))*(num%10);
 
 }
 console.log(recsum("1234"))