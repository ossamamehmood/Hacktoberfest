var romanToInt = function(s) {
     const romanSymbols = {
         "I"     :        1,
 "V"    :         5,
 "X"     :       10,
 "L"     :        50,
 "C"      :      100,
 "D"     :        500,
 "M"     :        1000
     }
 
     let total = 0;
     for(let i = 0 ;  i< s.length ; i++){
       let currentValue = romanSymbols[s[i]];
       let nextValue = romanSymbols[s[i+1]];
       
       if(nextValue > currentValue){
         total -=  currentValue
       }
       else{
         total +=  currentValue
       }
     }
   
 
   return total; 
 };

console.log(romanToInt("MCMXCIV"))
