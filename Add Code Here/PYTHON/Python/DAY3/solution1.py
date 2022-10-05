class Solution:
    def romanToInt(self, s: str) -> int:
        
        # Initialize the roman numerals
        roman = {
            "I" : 1,
            "V" : 5,
            "X" : 10,
            "L" : 50,
            "C" : 100,
            "D" : 500,
            "M" : 1000
        }
        
        # Go throught the given string and convert to int
        j = 0
        integer = 0
        while j < len(s):
            if j+1 < len(s) and roman[s[j]] < roman[s[j+1]]:
                integer += (roman[s[j+1]]-roman[s[j]])
                j += 2
            else:
                integer += roman[s[j]]
                j += 1
        return integer
