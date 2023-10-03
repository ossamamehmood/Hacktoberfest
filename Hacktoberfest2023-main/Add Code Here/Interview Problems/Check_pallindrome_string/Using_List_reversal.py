def is_palindrome(s):
    s = s.lower()  # Convert to lowercase for case-insensitive comparison
    s_list = list(s)
    return s_list == s_list[::-1]


# Test cases
test_strings = ["racecar", "level", "python", "A man a plan a canal Panama", "Madam, in Eden, I'm Adam"]

for s in test_strings:
    result = is_palindrome(s)
    if result:
        print(f"'{s}' is a palindrome.")
    else:
        print(f"'{s}' is not a palindrome.")