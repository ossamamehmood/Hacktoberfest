/* Gemstones Problem solutions */

function gemstones(arr) {

    let wordCount = 1;
    let wordsCharArr = [];
    let gemstonesCount = 0;

    let firstStrCharArr = arr[0].split("");

    while (wordCount < arr.length) {
        let strArr = arr[wordCount].split("");
        wordsCharArr.push(strArr);
        wordCount++;
    }

    for (const char in firstStrCharArr) {
        let charCount = 0;
        for (const word in wordsCharArr) {
            if (wordsCharArr[word].includes(firstStrCharArr[char])) {
                charCount++;
            }
        }
        if (charCount === wordsCharArr.length) {
            gemstonesCount++;
        }
    }

    return gemstonesCount;
    
}

let gemstonesCount = gemstones(["basdfj", "asdlkjfdjsa", "bnafvfnsd", "oafhdlasd"]);
console.log(gemstonesCount);
