# https://codeforces.com/problemset/problem/1/A

def sq_side(rec_side, sq_side):
    if (rec_side % sq_side == 0):
        return rec_side
    else:
        return sq_side*((rec_side // sq_side) + 1)


n, m, a = map(int, input().strip().split())
# Converting rectangle into small squares of side a
n = sq_side(n, a)
m = sq_side(m, a)
# print(n, m)
ar_th_sq = n * m
ar_flagstone = a * a
num_flagstone = ar_th_sq // ar_flagstone
print(num_flagstone)
