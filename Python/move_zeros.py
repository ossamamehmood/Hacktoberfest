'''
[0,2,0,1,4]=>[2,1,4,0,0]
'''

# lis1 = [0,2,0,1,4] test case 1
lis = [0,0,1]
count = 0
# method 1
for i in lis:
    if i!=0:
        lis[count]=i
        count +=1


for i in range(count,len(lis)):
    lis[i]=0


# method 2
'''for i in range(len(lis)-1,-1,-1):
    if lis[i]==0:
        lis.pop(i)
        lis.append(0)'''
print(lis)