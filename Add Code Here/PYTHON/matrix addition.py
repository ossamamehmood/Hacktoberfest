print("Enter Row and Column Size of First Matrix: ", end="")
rowOne = int(input())
colOne = int(input())
print("Enter Row and Column Size of Second Matrix: ", end="")
rowTwo = int(input())
colTwo = int(input())

if rowOne==rowTwo and colOne==colTwo:
    matOne = []
    print("\nEnter " +str(rowOne*colOne)+ " Elements for First Matrix: ")
    for i in range(rowOne):
        matOne.append([])
        for j in range(colOne):
            num = int(input())
            matOne[i].append(num)

    matTwo = []
    print("\nEnter " +str(rowTwo*colTwo)+ " Elements for Second Matrix: ")
    for i in range(rowTwo):
        matTwo.append([])
        for j in range(colTwo):
            num = int(input())
            matTwo[i].append(num)

    matThree = []
    for i in range(rowOne):
        matThree.append([])
        for j in range(colTwo):
            matThree[i].append(matOne[i][j]+matTwo[i][j])

    print("\nAddition Result:")
    for i in range(rowOne):
        for j in range(colOne):
            print(matThree[i][j], end=" ")
        print()
else:
    print("\nDimension Mismatched!")
