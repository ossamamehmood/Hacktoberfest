print("Enter First Binary Number: ")
nOne = int(input())
print("Enter Second Binary Number: ")
nTwo = int(input())

nOne = str(nOne)
nTwo = str(nTwo)
iSum = int(nOne, 2) + int(nTwo, 2)
bSum = bin(iSum)

print("Result = " + bSum)
