def bubble_sort(list):
    for i in range(0, len(list)-1):
        for j in range(len(list)-1):
            if (list[j] > list[j+1]):
                temp = list[j]
                list[j] = list[j+1]
                list[j+1] = temp
    return list


list = [5, 3, 8, 6, 7, 2]

print(bubble_sort(list))
