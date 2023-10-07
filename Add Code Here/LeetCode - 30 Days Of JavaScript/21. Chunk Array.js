var chunk = function(arr, size) {
    let answer = [];
    for(let i = 0; i < arr.length; i += size){
        answer.push(arr.slice(i, i+size))
    }   
   return answer;
};


/** Follow on Github : @utsxvrai  **/