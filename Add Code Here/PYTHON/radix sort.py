import random, time


def MaxNumLength(arr: list):
    maxNum = max(arr)
    length = 1

    while maxNum != 0:
        maxNum //= 10
        length += 1 

    return length


def count(arr: list, n: int):
    count = [0] * 10

    for num in arr:
        digit = num % (10**n) // 10 ** (n - 1)
        count[digit] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    arrCopy = arr.copy()

    for i in range(1, len(arr) + 1):
        num = arrCopy[-i]
        digit = num % (10**n) // 10 ** (n - 1)
        index = count[digit] - 1
        arr[index] = num
        count[digit] -= 1


def radixSort(arr: list):
    maxLength = MaxNumLength(arr)
    for i in range(1, maxLength):
        count(arr, i)


array = [i for i in range(10000)]
random.shuffle(array)
print(f"Unsorted array\n{array}")
startTime = time.time()
radixSort(array)
endTime = time.time()
print(f"Sorted array\n{array}")

duration = endTime - startTime
print(f"\nDuration: {duration}seconds")
