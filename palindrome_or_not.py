def is_palindrome(s):
    s = s.lower()  # Convert the string to lowercase for case-insensitive comparison
    s = ''.join(e for e in s if e.isalnum())  # Remove non-alphanumeric characters
    return s == s[::-1]  # Check if the string is equal to its reverse

# Test cases
string1 = "racecar"
string2 = "hello"
string3 = "A man, a plan, a canal, Panama"

print(is_palindrome(string1))  # True
print(is_palindrome(string2))  # False
print(is_palindrome(string3))  # True
#Here's how the is_palindrome function works:

#It converts the input string to lowercase to make the comparison case-insensitive.

#It removes non-alphanumeric characters from the string using a generator expression and join.

#It checks if the modified string is equal to its reverse using slicing ([::-1]).

#You can use this function to determine if a given string is a palindrome or not. It returns True if the string is a palindrome and False otherwise.
