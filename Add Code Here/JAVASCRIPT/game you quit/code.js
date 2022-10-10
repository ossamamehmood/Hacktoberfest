let win=0; 
for(let i=0;i<100;i++){
    let numberArray=[];
    let samplevalue=Math.ceil(100/Math.E);
    for(let i=0;i<100;i++){
        numberArray.push(Math.random()/Math.random()*Math.random()/Math.random()*1000000000000000000);
    }
    let maxOfArray=Math.max(...numberArray);
    let sampleArray=[];
    for(let k=0;k<samplevalue;k++){
        sampleArray[k]=numberArray[k];
    }
    maxOfSample=Math.max(...sampleArray);
    let selectedNumber=0;
    for(let j=samplevalue;j<100;j++){
        if(numberArray[j]>=maxOfSample){
            selectedNumber=numberArray[j];
            break;
        }
        
    }
    if(selectedNumber>=maxOfArray){
        win++;
    }
}
console.log(`Win percentage is ${win}%`);


