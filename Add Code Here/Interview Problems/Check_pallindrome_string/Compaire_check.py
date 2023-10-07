def is_palindrome(s): ## get list 
    reversed_s = s[::-1] ## reverse and store in third variable
    return s == reversed_s ## check whether it same or not


# Test cases
test_strings = ["racecar", "level", "python", "A man a plan a canal Panama", "Madam, in Eden, I'm Adam"]

for s in test_strings:
    result = is_palindrome(s)
    if result:
        print(f"'{s}' is a palindrome.")
    else:
        print(f"'{s}' is not a palindrome.")