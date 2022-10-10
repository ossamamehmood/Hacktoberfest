function odd(length){
    for(i = 1; i <= length; i++){
        if(i % 2 == 1){
            console.log(i)
        }
    }
}
function even(length){
    for(i = 1; i <= length; i++){
        if(i % 2 == 0){
            console.log(i)
        }
    }
}
//example odd(20), even(20)
even(20)