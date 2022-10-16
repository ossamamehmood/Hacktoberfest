# Sorting Algorithm: Selection Sort
# Time Complexity: O(n^2) , where n is the no of elements
# Space Complexity: O(1)
def selectionSort(arr):
    print(f"Unsorted Array: {arr}")
    # Size of Array
    size = len(arr)
    swaps = 0

    i = 0
    while i < size-1:
        j = i + 1
        while j <= size-1:
            if arr[i] > arr[j]:
                # swap
                arr[i], arr[j] = arr[j], arr[i]
                swaps = swaps + 1

            j = j + 1
        i = i + 1
        print(f"{arr}")
    print(f"Steps: {i} \t Swaps: {swaps}")
    return arr

a = [2,6,9,4,8,1,5,7]
sorted_arr = selectionSort(a)
print(f"Sorted Array is: {sorted_arr}")