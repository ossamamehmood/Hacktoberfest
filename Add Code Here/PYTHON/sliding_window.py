def maximum_sum(array, window_size):
    array_size = len(array)
    if array_size <= window_size:
        return -1

    window_sum = 0
    for i in range(window_size):
        window_sum += array[i]

    max_sum = window_sum

    for i in range(array_size - window_size):
        window_sum = window_sum - array[i] + array[i + window_size]
        max_sum = max(max_sum, window_sum)

    return max_sum


arr = [80, -50, 90, 100]
k = 3

answer = maximum_sum(arr, k)
print(answer)
