pos=-1

def bsearch(list,n):
    l=0
    u=len(list)-1

    while l <= u:
        mid=(l+u) // 2 #initiating low high mid value
        if list[mid]==n:
         globals()['pos']==mid

         return True
        


        else:
           if list[mid]<n:
            l=mid+1 #changing mid value if element not found
           else:
            u=mid-1

    return False
list=[45,65,78,85,90]
n=(int(input('enter the no u want to search')))
if bsearch(list, n):
    print('found at',pos+1)
else:
    print('not found')
