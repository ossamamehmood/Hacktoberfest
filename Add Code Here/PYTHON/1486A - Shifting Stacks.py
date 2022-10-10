# https://codeforces.com/contest/1486/problem/A
from collections import Counter


def stack(length, arr):
    # print(arr)
    for i in range(length - 1):
        store = arr[i] - i
        arr[i] -= store
        # print(store)
        if store < 0:
            return 'NO'
        else:
            arr[i + 1] += store
    # print(arr)
    if length > 1 and (arr[-1] <= arr[-2]):
        return 'NO'
    return 'YES'


for test in range(int(input())):
    n = int(input())
    lst = list(map(int, input().split()))
    print(stack(n, lst))
