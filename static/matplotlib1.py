"""import matplotlib.pyplot as p
s=[50,30,10,5,5]
l=["Python","Java","C++","C","JavaScript"]
p.pie(s,labels=l)
p.show()
"""
import numpy
row1 = int(input("Enter no: of rows of first matrix: "))
column1 = int(input("Enter no: of columns of first matrix: "))
row2 = int(input("Enter no: of rows of second matrix: "))
column2 = int(input("Enter no: of columns of second matrix: "))
arr10 = numpy.array([[0]*column1]*row1)
arr11 = numpy.array([[0]*column2]*row2)
arr12 = numpy.array([[0]*column2]*row1)
if column1==row2:
    print("Enter elements of first matrix: ")
    for i in range(row1):
        for j in range(column1):
            arr10[i][j] = int(input())
    print("Enter elements of second matrix: ")
    for i in range(row2):
        for j in range(column2):
            arr11[i][j] = int(input())
    for i in range(row1):
        for j in range(column2):
            sum=0
            for k in range(column1):
                sum = sum + arr10[i][k] * arr11[k][j]
            arr12[i][j] = sum
    print("Result array: ")
    print(arr12)
else:
    print("no: of columns of first matrix are not equal to no: of rows of second matrix.")