# Python3 program to create Special triangle.
# Function to generate Special Triangle.
def printTriangle(A):
		
		# Base case
		if (len(A) < 1):
			return

		# Creating new array which contains the
		# Sum of consecutive elements in
		# the array passes as parameter.
		temp = [0] * (len(A) - 1)
		for i in range( 0, len(A) - 1):
		
			x = A[i] + A[i + 1]
			temp[i] = x
		

		# Make a recursive call and pass
		# the newly created array
		printTriangle(temp)
		
		# Print current array in the end so
		# that smaller arrays are printed first
		print(A)
	

# Driver function
A = [ 1, 2, 3, 4, 5 ]
printTriangle(A)

