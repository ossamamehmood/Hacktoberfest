const numberMask = (number) => number.replace(/\d(?=\d{3})/g, "*");
// replace number from inside curly braces regex with your number you want to don't masking it
console.log(numberMask("1234567890"));
// Example Output: *******890