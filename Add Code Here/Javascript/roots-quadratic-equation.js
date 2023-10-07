//Roots Quadratic equation

//Add the numbers in A, B, C
var A = 10;
var B = 20.1; 
var C = 5.1; 
var delta = (B*B) - (4* A * C); 
var result = 'Impossible to calculate';

if ((A === 0) || delta < 0){ 
    console.log(result); 
} else { 
    var x1 = (-B + Math.sqrt(delta)) / (2*A); 
    var R1 = Number(x1); 
    console.log("R1 = "+R1.toFixed(5)); 
    var x2 = (-B - Math.sqrt(delta))/(2*A); 
    var R2 = x2; 
    console.log("R2 = "+R2.toFixed(5)); }
