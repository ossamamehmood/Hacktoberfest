def is_palindrome(s):
    s = s.lower()  # Convert to lowercase for case-insensitive comparison
    if len(s) <= 1:
        return True
    if s[0] != s[-1]:
        return False
    return is_palindrome(s[1:-1]) ## call it recursively


# Test cases
test_strings = ["racecar", "level", "python", "A man a plan a canal Panama", "Madam, in Eden, I'm Adam"]

for s in test_strings:
    result = is_palindrome(s)
    if result:
        print(f"'{s}' is a palindrome.")
    else:
        print(f"'{s}' is not a palindrome.")