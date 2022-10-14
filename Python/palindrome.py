def checkpalindrome(s):
    low =0
    high = len(s)-1
    while low<high:
        if s[low]!=s[high]:
            return False
            break
        low = low+1
        high = high-1
    else:
        return True

# A different approachh to find the palindrome using python lang
# def isPalindrome(s):
#     if s == s[::-1]:
#         return True
#     else:
#         return False


s = input("Enter a string to check if its palindrome or not\n")

print ("IsPalindrome" if checkpalindrome(s) else "NotPalindrome")
    