# https://codeforces.com/problemset/problem/12/A

code_list = []
for i in range(3):
    code_list += list(input().strip())
# print(code_list)
if (code_list == code_list[::-1]):
    print("YES")
else:
    print("NO")
