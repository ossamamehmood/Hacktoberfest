p = int(input("enter the column number for matrix1:"))
q = int(input("enter the column number for matrix2:"))

n = int (input("enter the column number for matrix 1/ row number matrix2:"))

# accepting matrix1 values and displaying matrix 1

print ("enter the elements for matrix 1:")

matrix1 = [[int (input ()) for i in range (n)] for j in range (p)]

print ("matrix 1:")

for i in range (p):

    for j in range (n):

        print(format (matrix1[i][j],"<5"), end="")
    
print ()

# accepting matrix2 values and displaying matrix2

print ("enter the elements for matrix2:")

matrix2 = [[int (input()) for i in range (q)] for j in range (n)]

print ("matrix2:")


for i in range (n):

    for j in range (q):

        print (format (matrix2[i][j],"<5"), end="")

print ()

# final matrix

result = [[0 for i in range(q)] for j in range (p)]

for i in range (p) :

    for j in range (q):

        for k in range (n):

            result[i][j] = result[i][j] + matrix1[i][k] * matrix2[k][j]

# displaying the result

print ("the result of matrix multiplication  is:")

for i in range (p):

    for j in range (q):

        print (format (result [i][j], "<5"), end="")

print()







####time complexity is O(n^3)######