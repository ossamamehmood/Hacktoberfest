# Python Program to Print Right Angled Triangle Star Pattern

rows = int(input("Please Enter the Total Number of Rows  : "))

print("Right Angled Triangle Star Pattern") 
for i in range(1, rows + 1):
    for j in range(1, i + 1):
        print('*', end = '  ')
    print()
