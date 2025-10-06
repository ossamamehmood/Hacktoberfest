def add(a,b):
    return (a+b)
def sub(a,b):
    return (a-b)
def mult(a,b):
    return (a*b)
def div(a,b):
    return (a//b)


print("1. Addition")
print("2 . Subtraction")
print("3. Multiplication")
print("4. Division")


while True:
    choice = int(input("Enter Choice "))
    if choice == 1 or choice ==2 or choice ==3 or choice ==4 or choice ==5:
        a= int(input("Enter 1st number"))
        b= int(input("Enter 2nd number"))
        if choice == 1:
            print(add(a,b))
        elif choice == 2:
            print(sub(a,b))
        elif choice == 3:
            print(mult(a,b))
        elif choice == 4:
            print(div(a,b))
        else:
            print("Enter valid choice")
            break