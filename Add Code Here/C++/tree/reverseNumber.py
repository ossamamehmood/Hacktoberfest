try:
    n=int(input('Enter number to reverse :'))
    rev=0
    while(n!=0):
        r=int(n%10)
        rev=rev*10+r
        n=int(n/10)
    print('reversed number of given number =', rev)

except ValueError:
    print('Given input is not a accepted value') 
