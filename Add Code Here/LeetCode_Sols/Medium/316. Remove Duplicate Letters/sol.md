It is very similar to your code for the `smallestSubsequence()` function. The only difference is that the `removeDuplicateLetters()` function does not append the characters from the stack to a string in a specific order. Instead, it pops the characters from the stack and adds them to the string until the stack is empty.

Here is a summary of the algorithm:

1. Initialize a stack to store the characters in the string.
2. Initialize a boolean array `inStack` to track whether a character is already in the stack.
3. Initialize an integer array `lastIndex` to track the last index of each character in the string.
4. Iterate over the string:
    * If the character at the current index is already in the stack, skip it.
    * While the stack is not empty and the current character is less than the character at the top of the stack, and the current index is less than the last index of the character at the top of the stack:
        * Pop the character at the top of the stack and set the corresponding entry in the `inStack` array to `false`.
    * Push the current character onto the stack and set the corresponding entry in the `inStack` array to `true`.
5. Pop the characters from the stack and add them to a string until the stack is empty.
6. Return the string.

The time complexity of the algorithm is O(n), where n is the length of the string. This is because the algorithm needs to traverse the string twice.

The space complexity of the algorithm is O(n), since it needs to store the stack, the boolean array, and the integer array.
