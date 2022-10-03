
def split(arr,i,sum):
    
    def helper(arr, n, start, lsum, rsum):
 

        if (start == n):
              return lsum == rsum
 

        if (arr[start] % 5 == 0):
                  lsum += arr[start]
 
        elif (arr[start] % 3 == 0):
                  rsum += arr[start]
 
    
        else:
 
      
                return (helper(arr, n, start + 1, lsum + arr[start], rsum) or helper(arr, n, start + 1,
                lsum, rsum + arr[start]));
 
        return helper(arr, n, start + 1, lsum, rsum)
    
    
    
    
    
    
    
    
    return helper(arr, len(arr), 0, 0, 0)
    
n = input()
arr = [int(ele) for ele in input().split()]
ans = split(arr,0,0)
if ans is True:
    print('true')
else:
    print('false')