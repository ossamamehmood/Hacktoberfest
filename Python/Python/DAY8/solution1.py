class Solution:
    def isPalindrome(self, s: str) -> bool:
        palindrome = ""
        for i in s:
            if i.isalnum():
                if i.isalpha(): i = i.lower()
                palindrome += i
        if palindrome == palindrome[::-1]:
            return True
        return False
