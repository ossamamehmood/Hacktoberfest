size = 7

m = (2 * size) - 2

for i in range(0, size):

    for n in range(0, m):
        print(end=" ")

    m = m - 1

    for j in range(0, i + 1):
        print("*", end=" ")
    print(" ")
