def counting_sort(arr, position):
    """Helper function to sort the array based on significant places, position is the place value"""
    n = len(arr)
    output = [0] * n
    count = [0] * 10  # As we're dealing with decimal numbers

    # Count occurrences of each digit at the given position in the input array
    for i in range(n):
        index = (arr[i] // position) % 10
        count[index] += 1

    # Update count[i] to store the position of the next occurrence of the same digit
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Build the output array
    i = n - 1
    while i >= 0:
        index = (arr[i] // position) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    # Copy the sorted values back to the original array
    for i in range(n):
        arr[i] = output[i]


def radix_sort(arr):
    """Main Radix Sort function"""
    # Find the maximum number to determine the number of digits
    max_num = max(arr)

    # Sort the array for every digit
    # Start from the least significant digit and move to the most significant digit
    position = 1
    while max_num // position > 0:
        counting_sort(arr, position)
        position *= 10

    return arr


# Example usage:
arr = [170, 45, 75, 90, 802, 24, 2, 66]
sorted_arr = radix_sort(arr)
print(sorted_arr)
