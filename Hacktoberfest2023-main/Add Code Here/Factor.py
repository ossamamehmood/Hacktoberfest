
num = 100

factors = []
for i in range (1, num//2 + 1):
    if ((num) % i == 0):
        factors.append(i)


factors.append(num)
print(factors)

# 9 digits = 20 sec
# 10 digits = 229.622 sec