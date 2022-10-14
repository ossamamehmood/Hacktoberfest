# https://codeforces.com/problemset/problem/11/A

n, d = map(int, input().strip().split())
lst = list(map(int, input().strip().split()))
count = 0
for i in range(1, n):
    if (lst[i] > lst[i - 1]):
        continue
    else:
        temp = ((lst[i - 1] - lst[i]) // d) + 1
        count+=temp
        lst[i] += temp * d
        # print(count)
    # while (lst[i - 1] >= lst[i]):
# print(lst)
print(count)
