def mergeSort(li):
    if len(li) <= 1:
        return
    mid = len(li) // 2
    L = li[:mid]
    R = li[mid:]
    mergeSort(L)
    mergeSort(R)
    i = j = k = 0
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            li[k] = L[i]
            i += 1
        else:
            li[k] = R[j]
            j += 1
        k += 1
    while i < len(L):
        li[k] = L[i]
        i += 1
        k += 1
    while j < len(R):
        li[k] = R[j]
        j += 1
        k += 1


def quicksort(li):
    if len(li) <= 1:
        return li
    pivot = li[0]
    left = [x for x in li[1:] if x < pivot]
    right = [x for x in li[1:] if x >= pivot]
    return quicksort(left) + [pivot] + quicksort(right)

l_unsorted = [2, 6, 13, 5, 7, 4, 330, 79, 26, 109]
print(f"Quick Sort:\n{quicksort(l_unsorted)}")

mergeSort(l_unsorted)
print(f"Merge Sort:\n{l_unsorted}")
