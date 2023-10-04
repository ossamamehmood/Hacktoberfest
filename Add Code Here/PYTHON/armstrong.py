n = input("Enter a number: ")

res = 0
for digit in n:
    res += int(digit) ** 3

if res == int(n):
    print("Armstrong")
else:
    print("Not Armstrong")