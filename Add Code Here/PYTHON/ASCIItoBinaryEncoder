#ascii to binary
chara=str(input())
bina=""
for c in chara:
    ascival=ord(c)
    #print(ascival," ")
    bin=0
    for i in range(9):
        bin+=ascival%2
        bin/=10
        ascival=ascival//2
    bin*=1000000000
    bin+=0.001
    bin=int(bin)
    leng=len(str(bin))
    if leng<8:
        bina+=("0"*(8-leng)+str(bin))
    else:
        bina+=str(bin)
    
print(bina)
