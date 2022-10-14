class Solution:
    dp_price=[[0 for i in range(1000)]for j in range(1000)]
    maxprof=float('inf')
    def cutRod(self, price, n):
        #code here
        for i in range(n):
            self.dp_price[0][i]=self.dp_price[i][0]=0
        self.dp_price[0][0]=0
        l_array=[]
        for i in range(1,n+1):
            l_array.append(i)
        return self.cutHelper(price,n,l_array)
    def cutHelper(self,price,n,l):
        for i in range(1,n+1):
            for j in range(1,n+1):
                if(l[i-1]<=j):
                    self.dp_price[i][j]=max(self.dp_price[i-1][j],price[i-1]+self.dp_price[i][j-l[i-1]])
                    #print(self.dp_price[i][j],"poi")
                else:
                    self.dp_price[i][j]=self.dp_price[i-1][j]
            #print(self.dp_price)
        return self.dp_price[i][j]





#{
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.cutRod(a, n))

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends
