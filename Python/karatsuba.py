import math
from math import log10

def karatsuba(x,y):

#The base case for recursion

    if x <10 or y<10:
        return (x*y)
    
#sets n, the number of digits in the highest input number
    a= (int(log10(x) + 1), int(log10(y)+1))
    n=max(a)
# rounds up n/2

    n_2 = int(math.ceil(n/2.0))
#adds 1 if n is uneven
    n= n if n%2 ==0 else n+1

#splits the input numbers
    a,b = divmod(x, 10**n_2)
    c,d = divmod(y, 10**n_2)

#the recursive steps

    ac = karatsuba(a,c)
    bd = karatsuba(b,d)
    ad_bc= karatsuba((a+b), (c+d) -ac -bd)
    

#performs the multiplication   
    return (((10**n)*ac)+bd+((10**n_2)*(ad_bc)))
    
    
#To test if it works
import random
def test():
    for i in range(1000):
        x=random.randint(1, 10**5)
        y=random.randint(1, 10**5)
        expect= x*y
        result =karatsuba(x,y)
        if result != expect:
            return ("failed")
    return ('ok')
    
 


