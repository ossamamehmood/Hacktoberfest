a = int(input())
b = 0
if a > 9:
    for i in range(a):
        c = int(input())
        while c > 0:
            d = b%10
            b+=0
            c//=10
        print(b)
else:
    print("Invalid number")