def bubbleSort(A):

	for i in range(length):		for j in range(0,length-i-1):

			if A[j]>A[j+1]:

				A[j],A[j+1]=A[j+1],A[j]

mylist=input("Enter the list of numbers: ").split()

A=[int(i) for i in mylist]

length=len(A)

bubbleSort(A)

print("Sorted list:",A)
