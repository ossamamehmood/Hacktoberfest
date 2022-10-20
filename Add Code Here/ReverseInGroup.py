#reverseInGroups() Function


def reverseInGroups():
    for i in range (len(a)):
        for j in range (k-1):
            if a[j]<a[j+1]:
                a[j],a[j+1]=a[j+1],a[j]
                i+=1
                reverseInGroups()
                

                
#List Generation And Input Taking


a=[]
N=int(input())
k=int(input())
for i in range (1,N+1):
    a.append(i)
print(a)


#Printing The Generated Answer


reverseInGroups()
print(a)
