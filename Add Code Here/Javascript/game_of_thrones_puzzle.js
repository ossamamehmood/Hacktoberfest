/*
=========================================================================
Problem 
=========================================================================
Dothraki are planning an attack to usurp King Robert's throne. 
King Robert learns of this conspiracy from Raven and plans to 
lock the single door through which the enemy can enter his kingdom.

But, to lock the door he needs a key that is an anagram of a palindrome. 
He starts to go through his box of strings, checking to see if they can 
be rearranged into a palindrome. Given a string, determine if it can be 
rearranged into a palindrome. Return the string YES or NO.
=========================================================================
*/

function gameOfThrones(s) {
    let arr = s.split("");
  
    const charCount = {};
    let oddCharCount = 0;
  
    // Loop through the array of characters
    for (const char of arr) {
      // If the character is not in the charCount object, initialize it to 1
      if (!charCount[char]) {
        charCount[char] = 1;
      } else {
        // If the character is already in the charCount object, increment its count
        charCount[char]++;
      }
    }
  
    // Loop through the keys in the charCount object
    for (const char in charCount) {
      if (charCount[char] % 2 === 1) {
        oddCharCount++;
      }
    }
  
    // Decision logic 
    if (oddCharCount > 1) {
      return "NO";
    } else {
      return "YES";
    }
  }
  
  let result = gameOfThrones("aaabbbbccc");
  console.log(result);