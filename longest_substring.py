class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        
        start = 0
        end = 0
        seen = set()
        res = 0
        
        while start < len(s) and end < len(s):
            if s[end] not in seen:
                seen.add(s[end])
                end += 1
                res = max(res, end - start)
            else:
                seen.remove(s[start])
                start += 1
        return res
