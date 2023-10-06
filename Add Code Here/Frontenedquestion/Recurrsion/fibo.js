function fibo(n){
    debugger;

    if(n<2){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
console.log(fibo(4))