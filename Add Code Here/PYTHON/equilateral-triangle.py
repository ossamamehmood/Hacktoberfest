# Equilateral triangle pyramid

s = 5
asciiStart = 65
m = (2 * s) - 2
for i in range(0, s):
    for j in range(0, m):
        print(end = " ")

    m = m - 1
    for j in range(0, i + 1):
        alphabet = chr(asciiStart)
        print(alphabet, end=" ")
        asciiStart += 1
    print()
