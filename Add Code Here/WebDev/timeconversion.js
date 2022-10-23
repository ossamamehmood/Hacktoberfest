'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

function timeConversion(s) {
   let hour = (s[0] + s[1]);
    let minutes = (s[3] + s[4]);
    let seconds = (s[6] + s[7]);
    let hourType = s[8];
    if (hourType == 'P' && hour != "12") {
    hour = parseInt(hour) + 12;
    }
    if (hourType == 'A' && hour == 12) {
            hour = '00';
    }
    const newTime = (hour + ":" + minutes + ":" + seconds);
    return newTime; // Write your code here

}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const s = readLine();

    const result = timeConversion(s);

    ws.write(result + '\n');

    ws.end();
}
