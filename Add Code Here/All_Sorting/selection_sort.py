def selectionSort(array):
    size = len(array)
    for ind in range(size):
        min_index = ind

        for j in range(ind + 1, size):
            # select the minimum element in every iteration
            if array[j] < array[min_index]:
                min_index = j
        # swapping the elements to sort the array
        (array[ind], array[min_index]) = (array[min_index], array[ind])

def main():
    arr = []
    n = int(input("Enter the number of elements: "))
    for i in range(n):
        element = int(input(f"Enter element {i+1}: "))
        arr.append(element)

    selectionSort(arr)
    print('The array after sorting in Ascending Order by selection sort is:')
    print(arr)

if __name__ == "__main__":
    main()

