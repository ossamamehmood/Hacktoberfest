const myAtoi = function(str) {
    if(str.length===0||!(parseInt(str)*parseInt(str)>=0)){
        return 0;
    }
    if(parseInt(str)>2147483647){
        return 2147483647;
    }
    if(parseInt(str)<-2147483648){
        return -2147483648;
    }
    return parseInt(str);
};