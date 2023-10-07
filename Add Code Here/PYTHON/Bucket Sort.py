def insertion_sort(bucket):
    for i in range(1, len(bucket)):
        up = bucket[i]
        j = i - 1
        while j >=0 and bucket[j] > up:
            bucket[j + 1] = bucket[j]
            j -= 1
        bucket[j + 1] = up
    return bucket

def bucket_sort(arr):
    arr_max, arr_min = max(arr), min(arr)
    bucket_range = (arr_max - arr_min) / len(arr)
    count_list = []
    for i in range(len(arr) + 1):
        count_list.append([])
    for i in range(len(arr)):
        diff = int((arr[i] - arr_min) // bucket_range)
        if diff != len(arr):
            count_list[diff].append(arr[i])
        else:
            count_list[len(count_list) - 1].append(arr[i])

    for i in range(len(count_list)):
        count_list[i] = insertion_sort(count_list[i])

    k = 0
    for i in range(len(count_list)):
        for j in range(len(count_list[i])):
            arr[k] = count_list[i][j]
            k += 1

# Driver code
arr = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434]
bucket_sort(arr)
print("Sorted array is:", arr)
