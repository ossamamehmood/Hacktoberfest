#https://leetcode.com/problems/reverse-vowels-of-a-string/
class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        out = ""
        vowels = set(["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"])  
        a = list(s)

        i = 0
        j = len(a) - 1

        while i < j:
            if a[i] in vowels and a[j] in vowels:
                a[i], a[j] = a[j], a[i]
                i += 1
                j -= 1
            elif a[i] in vowels:
                j -= 1
            else:
                i += 1
        
        out = ''.join(a)
        return out
