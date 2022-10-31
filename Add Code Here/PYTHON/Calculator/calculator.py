def add(a,b):  #Addition Function
    return a+b
def sub(a,b):  #Substract Function
    return a-b
def mul(a,b):  #Multiplication Function
    return a*b
def div(a,b):  #Divition Function
    return a/b
def choice(d,m): #Function for choice between operations
    if d.upper() == 'Y':
        print("\nHere You start ===> \n(press 'q' for quit)\n")
        while True:
            c = input("operator >> ")
            if c == 'q': #if user presses q then program will end as user wants to quit 
                break
            b = float(input("n >> "))
            if c == '+':
                m = add(m,b)
            if c == '-':
                m = sub(m,b)
            if c == '*':
                m = mul(m,b)
            if c == '/':
                m = div(m,b)
            print(">> ",m)
            d = c
    elif d.upper() == 'N':
        print("\nProgram Dead.... (x_x)\n")
    else:
        d = input("\nDO MORE OPERATION WITH THIS RESULT? (Y/N)\n")
        choice(d,m)

while True:
    print("---- x ----")
    print("1 - Addition")
    print("2 - Subtraction")
    print("3 - Multiplication")
    print("4 - Division")
    print("5 - Modulus")
    print("6 - Power/Exponent")
    choice = int(input("Enter your choice : "))
    a = int(input("Enter first operand :"))
    b = int(input("Enter second operand :"))
    
    if choice==1:
        print(str(a)+" + "+str(b)+" = "+str(a+b))
        
    elif choice==2:
        print(str(a)+" - "+str(b)+" = "+str(a-b))
    
    elif choice==3:
        print(str(a)+" * "+str(b)+" = "+str(a*b))
    
    elif choice==4:
        print(str(a)+"/ "+str(b)+" = "+str(a/b)) 
        
    elif choice==5:
        print(str(a)+" % "+str(b)+" = "+str(a%b))
    
    elif choice==6:
        print(str(a)+" to the power of  "+str(b)+" is "+str(pow(a,b)))
    
    else:
        print("Invalid Input. Quitting Program...")
        break
    
    ch=input("Continue?(Y/N) :")
    if ch=="N":
        break;
    
