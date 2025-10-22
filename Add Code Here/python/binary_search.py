def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid  # Found
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


# Example usage:
if __name__ == "__main__":
    numbers = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    target = 13
    result = binary_search(numbers, target)
    print(
        f"Element {target} found at index: {result}"
        if result != -1
        else "Element not found"
    )
