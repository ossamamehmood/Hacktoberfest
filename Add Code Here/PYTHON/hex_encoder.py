#ascii to binary
chara=str(input())
bina=""
for c in chara:
    ascival=ord(c)
    #print(ascival," ")
    li=""
    bin=0
    for i in range(8):
        bin*=10
        bin+=ascival%2
        ascival=ascival//2
    li+=str(bin)
    
    bit=li[::-1]
    bina+=bit
    
#prints binary code    
#print(bina)

#let's convert that binary into hexadecimal


line = bina
lis=[line[i:i+4] for i in range(0, len(line), 4)]


hexal="ABCDEF"
res=""

for li in lis:
    j=0
    for i in range(4):
        j+=int(li[i])*(2**(3-i))
    #print(j)
    if j<10:
        res+=str(j)
    else:
        res+=hexal[j-10]

    
print(res)   
        