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
            if c == 'q':
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
    print("\nCalculator starts..... ;)\n")
    a = float(input("n >> "))
    c = input("operator >> ")
    b = float(input("n >> "))
    if c == '+':
        m = add(a,b)
    if c == '-':
        m = sub(a,b)
    if c == '*':
        m = mul(a,b)
    if c == '/':
        m = div(a,b)
    print(">> ",m)
    d = input("\nDO MORE OPERATION WITH THIS RESULT? (Y/N)\n")
    choice(d,m)
