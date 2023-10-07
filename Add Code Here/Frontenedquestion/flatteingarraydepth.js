function depth(arr,n){
    let arre=[]
    let depth=1
    for(let element of arr){
        if(Array.isArray(element) && depth>n){
           const hui= depth(element,depth+1);
            arre=[...arre,...hui]
        }
        else{
            arre.push(element)
        }
    }
    return arre;
}
let arr=[1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]
console.log(depth(arr,2));