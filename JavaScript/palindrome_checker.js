function palindrome(str) {
  // Search the non-word character using regex
  let regex = /[\_\W]/g;

  // Reversing the word in params
  let strReverse = Array.from(str)
    .reverse()
    .join("")
    .toLocaleLowerCase()
    .replace(regex, "")
    .trim();

  // Assign the params to variable "string"
  let string = str.toLocaleLowerCase().replace(regex, "").trim();

  //   Matching the normal word and the reversed word from variable "string" and "strReverse"
  return string === strReverse ? true : false;
}

// The result
console.log(palindrome("eye"));
