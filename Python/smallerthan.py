def get_smallest(l,e):
    return[x for x in l if x<e]

l = [9,15,12,3,7,11]
e = 10
print(get_smallest(l,e))