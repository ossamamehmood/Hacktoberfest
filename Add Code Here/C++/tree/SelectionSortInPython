/*
* selection sort algorithm is idea of finding the smallest unsorted element and add it to the end of the sorted list.
* selection sort is of complexity O(n^2) and omega(n^2)

//          -- PSEUDO CODE --
// Repeat until no unsorted elements remain:
//     Search the unsorted part of data to find the smallest value.
//     Swap the smallest value found with the first element of unsorted part.
*/

def swap(array, firstIndex, secondIndex):
    temp = array[firstIndex]
    array[firstIndex] = array[secondIndex]
    array[secondIndex] = temp


def indexOfMinimum(array, startIndex):
    minValue = array[startIndex]
    minIndex = startIndex

    for i in xrange(minIndex + 1, len(array)):
        if array[i] < minValue:
            minIndex = i
            minValue = array[i]
    return minIndex


def selectionSort(array):
    for currentPos in range(0, len(array)):
        minIndex = indexOfMinimum(array, currentPos)
        swap(array, currentPos, minIndex)

    return
