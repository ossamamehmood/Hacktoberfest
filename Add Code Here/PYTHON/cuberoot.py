def diff(n, mid):
    if (n > (mid * mid * mid)):
        return (n - (mid * mid * mid))
    else:
        return ((mid * mid * mid) - n)
  
def cubicRoot(n):
 
    start = 0
    end = n

    e = 0.0000001
    while (True):
 
        mid = (start + end) / 2
        error = diff(n, mid)

        if (error <= e):
            return mid
        
        if ((mid * mid * mid) > n):
            end = mid
        else:
            start = mid
 
 
#example code
n = 3
print("Cubic root of", n, "is",
      round(cubicRoot(n), 6))