def knapsack_dp(wt,val,W,n):
    t=[[-1 for j in range(W+1)] for i in range(n+1)]
    #Base Condition Initialization
    for i in range(n+1):
        for j in range(W+1):
            if i==0 or j==0:
                t[i][j] = 0
    #Recursive Case
    for i in range(1,n+1):
        for j in range(1,W+1):
            if wt[i-1]<=W:
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j])
            elif wt[i-1]>W:
                t[i][j] = t[i-1][j]
    return t[n][W]
W = 6
wt = [1,2,3,6]
val = [1,2,4,6]
n=4
knapsack_dp(wt,val,W,n)
            
