#Program to remove the ith occurance of given word in a list where words repeat
c=[]
count=0
A=list(map(str,input().split()))
print(A)
B=input("Enter Word to remove: ")
N=int(input("Enter the occurrence to remove: "))
for i in A:
    if i==B:
        count+=1
        if count!=N:
            c.append(i)
    else:
        c.append(i)
if count==0:
    print("Item Not Found")
else:
    print("Updated list is: ",c)
