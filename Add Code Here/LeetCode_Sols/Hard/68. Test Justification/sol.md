The algorithm for the `fullJustify()` function can be summarized as follows:

1. Initialize a list to store the justified lines.
2. Iterate over the words array:
    * For each word, calculate the length of the current line, including the word and the spaces required to justify it.
    * If the current line length is greater than or equal to the maximum width, or if the current word is the last word in the array, then add the current line to the result list and start a new line.
    * Otherwise, add the current word to the current line.
3. For each justified line in the result list:
    * If the line contains only one word or if the line is the last line in the list, then pad the line with spaces until it reaches the maximum width.
    * Otherwise, calculate the number of spaces to add between each word on the line, and add the spaces accordingly.
4. Return the list of justified lines.

for example, consider the following input:

words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16

The output is as follows:

["This    is    an",
 "example  of  text",
 "justification."]

**Explanation:**

The first line has a length of 16, which is the maximum width. The second line has a length of 15, so one space is added between each word. The third line is the last line, so it is padded with spaces until it reaches the maximum width.
