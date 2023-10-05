class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(" ")
        rev= ""
        for word in words :
            rev = rev + word[::-1] + " "

        return rev.rstrip()
    