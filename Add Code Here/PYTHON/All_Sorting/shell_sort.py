# Shell sort in Python
# time complexity O(n*n)
# sorting by iterating with a gap
import math # for floor function
lst = [2, -1, 5, -10, 7, 9, 11] # the array
gap = math.floor(len(lst)/2) # gap for iteration
while (gap > 0):
    i = gap
    while (i < len(lst)):
        temp = lst[i] # for an eventual value change
        j = i # save the index
        while (j >= gap and lst[j-gap] > temp): # if index is greater than gap and the values in the range are greater than temp
            lst[j] = lst[j-gap]
            j-=gap # update index
        lst[j] = temp
        i += 1
    gap = math.floor(gap/2) # update gap (could be changed)

print(lst)

