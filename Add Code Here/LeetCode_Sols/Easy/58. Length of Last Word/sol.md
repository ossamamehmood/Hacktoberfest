**Algorithm:**

1. Initialize a count variable to 0.
2. Start at the end of the string and iterate backwards.
3. If the current character is a space and the count variable is 0, skip the character and continue iterating.
4. If the current character is not a space, increment the count variable and continue iterating.
5. If the current character is a space, return the count variable.
6. If the end of the string is reached, return the count variable.

**Time complexity:** O(n), where n is the length of the string.

**Space complexity:** O(1), as we only use a few constant variables.

For example, consider the following string:

"Hello World"

If we call the `lengthOfLastWord()` function on this string, the following steps will be taken:

1. The count variable is initialized to 0.
2. The function starts at the end of the string and iterates backwards.
3. The current character is a space and the count variable is 0, so the character is skipped and the function continues iterating.
4. The current character is 'l', so the count variable is incremented to 1 and the function continues iterating.
5. The current character is 'd', so the count variable is incremented to 2 and the function continues iterating.
6. The current character is 'o', so the count variable is incremented to 3 and the function continues iterating.
7. The current character is 'r', so the count variable is incremented to 4 and the function continues iterating.
8. The current character is 'W', so the count variable is incremented to 5.
9. The current character is a space, so the function returns the count variable, which is 5.

Therefore, the `lengthOfLastWord()` function will return `5` in this case.