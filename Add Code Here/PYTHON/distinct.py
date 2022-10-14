#Using count to find out the length of the distinct item in the list.
# def cDistinct(li):
#     count = 1
#     for i in range(1,len(li)):
#         if li[i] not in li[0:i]:
#             count = count+1

#     return count

#Using set to find out the distinct element in the list
def cDistinct(l):
    return len(set(l))


print(cDistinct([2,1,10,2,1,3,3]))      