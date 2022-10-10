n = int(input())

for i in range (n):
    m = int(input())
    l = list(map(int,input().split()))
    backup = l
    count = 0
    while True:
        rl = []
        ll = []
        x = backup[-1]
        for i in backup:
            if i <= x:
                ll.append(i)
            else :
                rl.append(i)
        l = ll+rl
        if backup != l:
            backup = l
            count = count + 1
        else :
            break
    print(count)