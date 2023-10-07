function palindrom(number){
   
    return number==number.split("").reverse().join("")
}
console.log(palindrom("atta"))