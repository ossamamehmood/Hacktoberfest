def mergeSort(A):
    #base case if the inpt array is just one or zero just return.
    if len(A) > 1:
        # splitting input array
        print('splitting' , A)
        mid = len(A) //2
        left =A[:mid]
        right = A[mid:]
        #recursive calls to mergeSort for left and right sub arrays
        mergeSort(left)
        mergeSort(right)
        #initializes pointers for left (i) nright (j) and output array (k)
        
#3 initialization operations
        i= j = k= 0
        #Transverse and merges the sorted arrays
        while i <len(left) and j<len(right):
#if left < right comparison operation
            if left[i] < right[j]:
#if left < right Assignment operation
                A[k]=left[i]
                i=i+1
            else:
#if right <= left assignment
                A[k] = right[j]
                j=j+1
            k=k+1
        
        while i<len(left):
#Assignment Operation
            A[k] = left[i]
            i=i+1
            k=k+1
        while j<len(right):
#Assignment Operation
            A[k] = right[j]
            j=j+1
            k=k+1
    print('merging', A)
    return(A)
        