Initialize a stack to store the characters in the smallest subsequence.
Initialize a boolean array inStack to track whether a character is already in the stack.
Initialize an integer array lastIndex to track the last index of each character in the string.
Iterate over the string:
If the character at the current index is already in the stack, skip it.
While the stack is not empty and the current character is less than the character at the top of the stack, and the current index is less than the last index of the character at the top of the stack:
Pop the character at the top of the stack and set the corresponding entry in the inStack array to false.
Push the current character onto the stack and set the corresponding entry in the inStack array to true.
Build the smallest subsequence by popping the characters from the stack and appending them to a string.
Return the smallest subsequence.
The time complexity of the algorithm is O(n), where n is the length of the string. This is because the algorithm needs to traverse the string twice.

The space complexity of the algorithm is O(n), since it needs to store the stack, the boolean array, and the integer array.