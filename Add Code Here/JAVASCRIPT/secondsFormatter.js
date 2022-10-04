/* 
Write a function, which takes a non-negative integer (seconds) as input and returns the time in a human-readable format (HH:MM:SS)
HH = hours, padded to 2 digits, range: 00 - 99
MM = minutes, padded to 2 digits, range: 00 - 59
SS = seconds, padded to 2 digits, range: 00 - 59
The maximum time never exceeds 359999 (99:59:59)
You can find some examples in the test fixtures.
*/

function humanReadable(seconds) {
  if (seconds === 359999) return '99:59:59';
  let HH = '0' + Math.floor(seconds / 3600);
  let MM = '0' + Math.floor((seconds % 3600) / 60);
  let SS = '0' + Math.floor((seconds % 3600) % 60);
  return `${HH.slice(-2)}:${MM.slice(-2)}:${SS.slice(-2)}`;
}

console.log(humanReadable(86400));
console.log(humanReadable(86399));
