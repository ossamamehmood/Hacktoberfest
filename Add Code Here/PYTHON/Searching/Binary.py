# Binary Search Algorithm

# Function to perform binary search
def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2  # Calculate the middle index

        if arr[mid] == target:
            return mid  # Element found, return its index
        elif arr[mid] < target:
            left = mid + 1  # Adjust left boundary
        else:
            right = mid - 1  # Adjust right boundary

    return -1  # Element not found

# Sample sorted list
sorted_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Target element to search for
target = 6

# Perform binary search
result = binary_search(sorted_list, target)

if result != -1:
    print(f"Element {target} found at index {result}.")
else:
    print(f"Element {target} not found in the list.")
