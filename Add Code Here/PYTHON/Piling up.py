import sys

def fun(n):
    if len(n)==2:
        #print(n)
        return max(n)
    a = n[0]
    b = n[-1]   
    #print(a,b)
    if a>=b:    
        removed_element = a
        #print(removed_element)
        if removed_element>=fun(n[1:]):
            return removed_element
        else:
            print('No')
            sys.exit()
    else:
        removed_element = b
        #print(removed_element)  
        if removed_element>=fun(n[:-1]):
            return removed_element
        else:
            print('No')
            sys.exit()
lst = list(map(int,input().split()))
if type(fun(lst))== int:
    print('Yes')



