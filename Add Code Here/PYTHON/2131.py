class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        dic = {}
        dic2 = {}
        count = 0
        for s in words:
            if s[0] == s[1]:
                dic2.setdefault(s, 0)
                dic2[s] += 1
            else:
                dic.setdefault(s, 0)
                dic[s] += 1
                temp = s[1]+s[0]
                if temp in dic.keys() and dic[temp] > 0:
                    dic[temp] -= 1
                    dic[s] -= 1
                    count += 4
        inc = False
        for k, v in dic2.items():
            if v % 2 == 0:
                count += v*2
            else:
                count += (v-1)*2
                inc = True
        if inc:
            count += 2
        return count
