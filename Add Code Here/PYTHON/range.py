def Rng(lst):
    laagte = lst[0]
    hoogste = lst[0]

    for getal in lst:
        if getal < laagte:
            laagte = getal

    for getal in lst:
        if getal > hoogste:
            hoogste = getal

    verschil = hoogste - laagte
    return verschil

def mediaan(lst):
    lst.sort()
    index = (len(lst) - 1) // 2

    if (len(lst) % 2):
        return lst[index]
    else:
        return (lst[index] + lst[index + 1]) / 2.0
