# def zerosubarray(l):
#     n =len(l)
#     for i in range(n):
#         for j in range(i+1, n+1):
#             if sum(l[i:j]) == 0:
#                 return True
#     return False
from operator import le


def zerosubarray(l):
    preset = 0
    h = set()
    for i in range(len(l)):
        preset += l[i]
        if preset == 0 or preset in h:
            return True
        h.add(preset)
    return False



print(zerosubarray([1,4,13,-3,-10,5]))