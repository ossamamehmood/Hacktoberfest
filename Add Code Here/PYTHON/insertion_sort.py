def insertion_sort(arr):
    # Traverse through the entire array starting from the second element
    for i in range(1, len(arr)):
        key = arr[i]  # Current element to be inserted into the sorted part
        j = i - 1

        # Move elements of arr[0..i-1], that are greater than key, one position ahead of their current position
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1

        # Insert  key into the sorted part
        arr[j + 1] = key

# sample
arr = [12, 11, 13, 5, 6]
insertion_sort(arr)
print("Sorted array is:", arr)
