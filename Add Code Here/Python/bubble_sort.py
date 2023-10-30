def bubble_sort(arr):
    n = len(arr)
    
    for i in range(n):
        # Flag to check if any swapping is done in this pass
        swapped = False
        
        # Last i elements are already in place, so we don't need to check them
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                # Swap the elements
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
                
        # If no swapping occurred in this pass, the array is already sorted
        if not swapped:
            break

# Example usage
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    
    print("Original array:", arr)
    bubble_sort(arr)
    print("Sorted array:", arr)
