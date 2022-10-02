def quicksort(a):
    if len(a)<=1:
        return a

    else:
        pivot = a.pop()

    greater =[]
    lower=[]

    for i in a:
        if i > pivot:
            greater.append(i)
        else:
            lower.append(i)    

    return quicksort(lower) + [pivot] + quicksort(greater)


arr=[56,3,4,2,6,3,7]

print(quicksort(arr))




