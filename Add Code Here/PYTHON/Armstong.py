on=int(input("Enter No. - "))
temp=on
dc=0
while temp>0:
    digit=temp%10
    dc=dc+digit**3
    temp=temp//10
if on==dc:
    print(on,"is an armstong number.")
else:
    print(on,"is not an armstong number.")
    
