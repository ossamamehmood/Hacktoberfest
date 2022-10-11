# https://codeforces.com/problemset/problem/14/A

input_list = []
i, j = map(int, input().strip().split())
for _ in range(i):
    input_list += input().strip('.').split()
length = len(max(input_list))
# print(length)
for k in range(len(input_list)):
    if (len(input_list[k]) < length):
        print(input_list[k] + (length - len(input_list[k])) * '.')
    else:
        print(input_list[k])
