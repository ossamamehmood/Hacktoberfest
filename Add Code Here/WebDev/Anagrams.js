# Check if two strings are anagram
var firstWord = "Deepak";
var secondWord = "Aman";

isAnagram(wordOne, wordTwo); // true

function isAnagram(one, two) {
  //Change both words to lowercase for case insensitivity..
  var a = one.toLowerCase();
  var b = two.toLowerCase();

  // Sort the strings, then combine the array to a string. Examine the outcomes.
  a = a.split("").sort().join("");
  b = b.split("").sort().join("");

  return a === b;
}
