from collections import OrderedDict
class Solution:
    def reversestring(self,s):
        s= s.replace(" ","")
        return "".join(OrderedDict.fromkeys(s[::-1]))
        

if __name__ == '__main__':
        s = "I AM AWESOME"

        ob = Solution()
        ans = ob.reversestring(s)
        print(ans)
