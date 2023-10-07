1. Calculate the number of strings of each length in the input array `words`.
2. Build an array `wcs` that maps each string length to an array of indexes to words of that length.
3. Create an array `memo` to store the longest string chain length for each word.
4. Start with the longest words and search backward (longest word to shortest word) to find the longest string chain.
5. For each word, recursively try to find a path from the word backward through predecessors, by comparing the word to all words that are one character shorter.
6. Find the longest path from the current word backward through shorter words.
7. Memorize the longest path from a word, so we don't have to recalculate it if we try to find the path from this word again.

The recursive `findPath()` function works like this:

1. If the word length is 1, then the longest string chain length is 1.
2. If the longest string chain length for the word is already stored in the memo array, then return the length.
3. Iterate over all predecessor words of the current word:
    * If the predecessor word is a predecessor of the current word, then recursively find the longest string chain length for the predecessor word.
    * Update the longest string chain length for the current word to the maximum of the current length and the length of the longest string chain for the predecessor word plus 1.
4. Store the longest string chain length for the current word in the memo array.
5. Return the longest string chain length for the current word.

The `isPredecessor()` function works like this:

1. Initialize a difference counter to -1.
2. Iterate over the characters in the current word in reverse order:
    * If the current character does not match the corresponding character in the predecessor word, then increment the difference counter.
    * If the difference counter is greater than 1, then return false.
3. Return true if the difference counter is 0 or 1, and the first characters of the current word and predecessor word match.
