# https://codeforces.com/problemset/problem/4/A

weight = int(input().strip())
if (weight % 2 == 0 and weight != 2):
    print("YES")
else:
    print("NO")
