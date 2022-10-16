list1=[]
list2=[]
num1=int(input("Enter number of elements for first list:"))
for i in range(1,num1+1):
    b=int(input("Enter element:"))
    list1.append(b)

num2=int(input("Enter number of elements for second list:"))
for i in range(1,num2+1):
    d=int(input("Enter element:"))
    list2.append(d)

list3=list1+list2
list3.sort()
print("Sorted list is:",list3)  
