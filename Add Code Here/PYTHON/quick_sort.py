'''
@Author: hariom09090
'''

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    
    #Pivot element
    pivot = arr[len(arr) // 2]
    
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort(left) + middle + quick_sort(right)

if __name__ == "__main__":
    user_input = input("Enter a list of numbers separated by spaces: ")
    unsorted_list = [int(x) for x in user_input.split()]

    # Sort the list using Quick Sort
    sorted_list = quick_sort(unsorted_list)

    # Print the sorted list
    print("Sorted list:", sorted_list)
