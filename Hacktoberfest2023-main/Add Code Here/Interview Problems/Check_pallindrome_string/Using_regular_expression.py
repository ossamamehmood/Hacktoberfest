import re

def is_palindrome(s):
    s = s.lower()  # Convert to lowercase for case-insensitive comparison
    s = re.sub(r'[^a-z0-9]', '', s)  # Remove non-alphanumeric characters
    return s == s[::-1]


# Test cases
test_strings = ["racecar", "level", "python", "A man a plan a canal Panama", "Madam, in Eden, I'm Adam"]

for s in test_strings:
    result = is_palindrome(s)
    if result:
        print(f"'{s}' is a palindrome.")
    else:
        print(f"'{s}' is not a palindrome.")