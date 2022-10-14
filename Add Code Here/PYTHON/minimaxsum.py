def miniMaxSum(arr):
    # Write your code here
    count = 0
    k=0
    num = arr[k]
    for i in range(len(arr)):
        
        if arr[i] != num:
            count = count+arr[i]
        if arr[i] == num:
            continue
        k = k+1
    return count

arr = [1,2,3,4,5]
print(miniMaxSum(arr))