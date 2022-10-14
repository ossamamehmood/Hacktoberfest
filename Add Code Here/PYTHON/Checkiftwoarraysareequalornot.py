
class Solution:
    #Function to check if two arrays are equal or not.
    def check(self,A,B,N):
        
        #code here
        A.sort()
        B.sort()
        for i in range(0,N):
            if A[i]!=B[i]: return False
        return True
