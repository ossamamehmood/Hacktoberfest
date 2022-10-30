const reverseNumber = (number)=>{
    let numberStr = number.toString();
    let numberArr = numberStr.split('');
    numberArr.reverse();
    numberStr = numberArr.join('');
    const intRes = parseInt(numberStr)
    return intRes
}