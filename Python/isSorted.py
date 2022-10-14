#using for loop

def isSorted(l):
    for i in range(1,len(l)):
        if l[i] < l[i-1]:
            return False
    else:
        return True

#using while loop
# def isSorted(l):
#     i =1
#     while i< len(l):
#         if l[i]<l[i-1]:
#             return False
#         i +=1
#     return True

# using sorted method.
# def isSorted(l):
#     s = sorted(l)
#     if s == l:
#         return True
#     else:
#         return False



l =[10,70,80,100]
print(isSorted(l))

