number=int(input())
temp=number
binary=""
while number>0:
    rem=number%2
    binary+=str(rem)
    number=number//2
print("The binary equivalent of "+str(temp)+" is "+binary[::-1]+" .")
