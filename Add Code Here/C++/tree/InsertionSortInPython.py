/*
* insertion sort algorithm idea is to build the sorted array in place, shifting elements out of the way if necessary to make room as you go.
* insertion sort is of complexity O(n^2) and omega(n)

//          -- PSEUDO CODE --
// Call the first element of the array "sorted".
// Repeat until all elements are sorted:
//     Look at the next unsorted element. Insert into the "sorted" portion by shifting the requisite number of elements.
*/

def insert(array, rightIndex, value):
    j = rightIndex
    while j >= 0 and array[j] > value:
        array[j + 1] = array[j]
        j = j - 1
    array[j + 1] = value


def insertionSort(array):
    for current in range(0, len(array) - 1):
        insert(array, current, array[current + 1])

    return
