from sys import stdin
from sys import maxsize as MAX_VALUE



def countMinStepsToOne(n) :
    
    dp = [-1 for x in range(n+1)]
    dp[1] = 0
    dp[0] = 0
    for i in range(2,n+1):
        ans1 = dp[i-1]
        if i%2==0:
            ans2 = dp[i//2]
        else:
            ans2 = MAX_VALUE
        if i%3 == 0:
            ans3 = dp[i//3]
        else:
            ans3 = MAX_VALUE
        dp[i] = 1+min(ans1,ans2,ans3)
        
    return dp[n]
        
        



#main
n = int(input())
dp = [-1 for x in range(n+1)] 
print(countMinStepsToOne(n,dp))
