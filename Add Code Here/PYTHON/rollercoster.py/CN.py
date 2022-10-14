n = 4
for i in range(n):
    for j in range(i):
        print('1',end='')
    for j in range(i+1):
        print(i+1,end='')
    print('1')
    