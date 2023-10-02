class Solution:
    def reverseWords(self, s: str) -> str:
        word=s.split()
        ans=''
        for i in word:
            ans+=i[::-1]
            ans+=' '
        return(ans[:-1])

        
