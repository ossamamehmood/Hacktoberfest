# Binary Search Implementation

# function for perfoming binary search
def binarySearchAlgo(lst, key):

    a = 0
    b = len(lst)
    while a < b:
        c = (a + b)//2
        if lst[c] > key:
            b = c
        elif lst[c] < key:
            a = c + 1
        else:
            return c
    return -1
 

# input a list of elements
lst = input('Enter the sorted list of numbers: ')

#split a element
lst = lst.split()
lst = [int(x) for x in lst]

# search for in list
key = int(input('The number to search for: '))

# call binary search function
index = binarySearchAlgo(lst, key)
if index < 0:
    print('{} was not found.'.format(key))
else:
    print('{} was found at index {}.'.format(key, index))
