#Bubble sort
def bubbleSort(arr):
	n = len(arr)
	swapped = False
	for i in range(n-1):
		for j in range(0, n-i-1):
			if arr[j] > arr[j + 1]:
				swapped = True
				arr[j], arr[j + 1] = arr[j + 1], arr[j]
		if not swapped:
			return


# Driver code to test above
arr = [78, 34, 5, 1, 22, 14, 90]

bubbleSort(arr)

print("Sorted:")
for i in range(len(arr)):
	print("% d" % arr[i], end=" ")
