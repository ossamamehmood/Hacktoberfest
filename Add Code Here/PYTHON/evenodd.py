def even_odd(l):
    even = [x for x in l if x%2==0]
    odd = [x for x in l if x%2!=0]
    return even, odd

l = [23,10,46,324,54,43,76,67,99]
print(even_odd(l))