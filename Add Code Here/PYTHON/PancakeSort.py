def flip(arr, i):
    """Reverse the array from 0 to i"""
    start = 0
    while start < i:
        arr[start], arr[i] = arr[i], arr[start]
        start += 1
        i -= 1

def pancake_sort(arr):
    """Pancake Sort main function"""
    n = len(arr)
    while n > 1:
        # Find the index of the largest element in arr[0...n-1]
        max_idx = arr.index(max(arr[0:n]))
        
        # Move the largest element to the end using two flips
        if max_idx != n - 1:
            # First, move the max element to the beginning
            flip(arr, max_idx)
            # Now, move the max element to its correct position
            flip(arr, n - 1)
        
        n -= 1
    return arr

