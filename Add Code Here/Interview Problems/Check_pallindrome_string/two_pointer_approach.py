def is_palindrome(s):
    s = s.lower()  # Convert to lowercase for case-insensitive comparison
    i, j = 0, len(s) - 1
    while i < j: ## start comparing i from starting of string and j is at ending of string
        if s[i] != s[j]:
            return False
        i += 1
        j -= 1
    return True


# Test cases
test_strings = ["racecar", "level", "python", "A man a plan a canal Panama", "Madam, in Eden, I'm Adam"]

for s in test_strings:
    result = is_palindrome(s)
    if result:
        print(f"'{s}' is a palindrome.")
    else:
        print(f"'{s}' is not a palindrome.")