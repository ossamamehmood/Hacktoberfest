def findSingle(arr, n):
    res = arr[0]
    for i in range(1,n):
        res ^= arr[i]
    return res


arr1 = [1,1,2,2,3,4,5,6,3,4,5,6,7]
n = len(arr1)
print("The only singe element is: ", findSingle(arr1, n))
