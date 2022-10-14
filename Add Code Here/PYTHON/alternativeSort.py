# Python 3 program to print an array
# in alternate sorted manner.

# Function to print alternate sorted
# values
def alternateSort(arr, n):

	# Sorting the array
	arr.sort()

	# Printing the last element of array
	# first and then first element and then
	# second last element and then second
	# element and so on.
	i = 0
	j = n-1
	
	while (i < j):
	
		print(arr[j], end =" ")
		j-= 1
		print(arr[i], end =" ")
		i+= 1

	# If the total element in array is odd
	# then print the last middle element.
	if (n % 2 != 0):
		print(arr[i])


# Driver code
arr = [1, 12, 4, 6, 7, 10]
n = len(arr)

alternateSort(arr, n)
