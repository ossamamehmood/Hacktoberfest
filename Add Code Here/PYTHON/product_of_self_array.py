'''
inp = [1,2,3,4]
out = [24,12,8,6]
'''
arr = [1, 2, 3, 4]
final_res = []


def product(arr):
    res = 1
    for i in arr:
        res *= i
    return res


for i in arr:
    res = arr.copy()
    res.remove(i)
    final_res.append(product(res))

print(final_res)