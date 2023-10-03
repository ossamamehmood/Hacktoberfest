temp = input("Enter comma-separated numbers: ")
tup = tuple(int(x) for x in temp.split(','))
print("The Tuple:", tup)

sum=0
for i in tup:
    sum+=i

res=sum/len(tup)
print("The Mean is:",res)