# https://codeforces.com/problemset/problem/9/A

dict_fraction = {0: '0/1', 1: '1/6', 2: '1/3', 3: '1/2', 4: '2/3', 5: '5/6', 6: '1/1'}
# dice_num = [0, 1, 2, 3, 4, 5, 6]
num = max(list(map(int, input().strip().split())))
prob = 7 - num
print(dict_fraction[prob])
