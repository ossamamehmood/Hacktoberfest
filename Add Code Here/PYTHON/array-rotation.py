#Rotate the elements of an array towards the left by the specified number of time(d)

def rotate(arr, d):
    # Create a new list to store the rotated elements
    new_list = []
    
    # Append elements from index 'd' to the end of the original array
    # and then append elements from the beginning of the array up to index 'd'
    new_list = arr[d:] + arr[0:d]
    
    return new_list

# Main program
if __name__ == '__main__':
    # Example array
    arr = [3, 4, 5, 6, 7, 1, 2]
    
    # Number of positions to rotate
    d = 2

    # Function call to rotate the array
    arr = rotate(arr, d)
    
    # Print the rotated array
    for i in arr:
        print(i, end=" ")
