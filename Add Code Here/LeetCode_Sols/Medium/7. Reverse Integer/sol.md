1. Convert the input integer `x` to a string `s`.
2. Create a new StringBuilder `reversed` to store the reversed string.
3. Iterate over the string `s` from the end to the beginning and append each character to the StringBuilder `reversed`.
4. If the first character of the string `s` is `-`, then append a `-` sign to the StringBuilder `reversed`.
5. Try to convert the StringBuilder `reversed` to an integer.
6. If the conversion is successful, return the integer. Otherwise, return 0.

Time complexity: O(n)
The time complexity is O(n) because the function needs to iterate over the input string once to reverse it.

Space complexity: O(n)
The space complexity is O(n) because the function needs to store the reversed string in the StringBuilder object.

**Example:**

Consider the following input integer `x`:

x = 123

The string `s` after the conversion is as follows:

s = "123"

The StringBuilder `reversed` after the iteration over the string `s` is as follows:

reversed = "321"

The integer `reversedInt` after the conversion is as follows:

reversedInt = 321

Since the conversion is successful, the function returns the integer `reversedInt`, which is 321.
