def binary_search(arr: list, target: int):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


arr = [1, 2, 3, 4, 5, 6]
target = 3

result = binary_search(arr=arr, target=target)  # index

if result != -1:
    print(result)
else:
    print("Element is not present")
