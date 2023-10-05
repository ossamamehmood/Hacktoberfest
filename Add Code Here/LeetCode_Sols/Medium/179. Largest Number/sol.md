1. Create an empty string `ans` to store the largest number.
2. Create an ArrayList `list` to store the string representations of the input numbers.
3. Iterate over the input array `nums` and add the string representations of the numbers to the ArrayList `list`.
4. Sort the ArrayList `list` in decreasing order using a custom comparator function that compares two strings by concatenating them together and comparing the resulting strings.
5. Iterate over the ArrayList `list` and append the strings to the string `ans`.
6. If the first character of the string `ans` is '0', then return the string "0". Otherwise, return the string `ans`.

The custom comparator function works as follows:

1. Concatenate the two input strings together.
2. Compare the two concatenated strings.
3. Return a negative integer, zero, or a positive integer depending on whether the first concatenated string is less than, equal to, or greater than the second concatenated string, respectively.

**Example:**

Consider the following input array `nums`:

nums = [10, 2, 3, 4, 5]

The ArrayList `list` after the iteration over the input array `nums` is as follows:

list = ["10", "2", "3", "4", "5"]

The ArrayList `list` after the sort operation is as follows:

list = ["5", "4", "3", "2", "10"]

The string `ans` after the iteration over the ArrayList `list` is as follows:

ans = "543210"

Since the first character of the string `ans` is not '0', the function returns the string `ans`.
