def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    L = [0] * (n1)
    R = [0] * (n2)
 
    for i in range(0, n1):
        L[i] = arr[left + i]
 
    for j in range(0, n2):
        R[j] = arr[mid + 1 + j]
 
    i = 0     
    j = 0     
    k = left     
 
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i =i+ 1
        else:
            arr[k] = R[j]
            j =j+ 1
        k += 1
 
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
 
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1
 
 
def mergeSort(arr, left, right):
    if left < right:
 
        mid = left+(right-l)//2

        mergeSort(arr, left, mid)
        mergeSort(arr, mid+1, right)
        merge(arr, left, mid, right)
 
arr=[]
arr=int(input("Enter an array"))
n = len(arr)
 
mergeSort(arr, 0, n-1)
print("\n\nSorted array is")
for i in range(n):
    print("%d" % arr[i],end=" ")
