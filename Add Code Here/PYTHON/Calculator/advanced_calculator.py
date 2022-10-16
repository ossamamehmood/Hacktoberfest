print(" #$#$ CALCULATOR $#$# ")
def sum(x,y):
    return x+y
def substract (x,y):
    return x-y
def mult(x,y):
    return x*y
def div(x,y):
    return x/y
def square(x):
    return x**2
def squareroot(x):
    return x**0.5
def cube(x):
    return x**3
def factorial(x):
    return x
def constant(x):
    return x
def prime(x):
    return x
print ("MAIN MENU")
print(" 1. addition ","\n 2. Substraction ,\n 3. Multiplication ","\n 4. Division ", "\n 5. Square ", "\n 6. Squareroot ", "\n 7. Cube ", "\n 8. Factorial ", "\n 9. Constant","\n 10. Check number prime or not")
choice=int(input(" Enter the choice :  "))
if choice <=8 :
    x=int(input(" Enter the number : "))

if choice <=4:
    y=int(input(" Enter the next number : "))

if choice==9:
    print(" The menu")
    print(" 1. Mass of electron ", "\n 2. Mass of proton  ","\n 3. Boltzmann constant","\n 4. Charge on electron ","\n 5. Plank constant ","\n 6. speed of light ","\n 7. Mass of nuetron ") 

if choice==1 :
    print(x,"+",y,"=",sum(x,y))
elif choice==2:
    print( x,"-",y,"=",substract(x,y))
elif choice==3:
    print(x,"*",y,"=",mult(x,y))
elif choice==4:
    print(x,"/",y,"=",div(x,y))
elif choice==5:
    print(x,"^2 = ", square(x))
elif choice==6:
    print(x,"^0.5 =", squareroot(x))
elif choice==7:
    print(x,"^3 =",cube(x))
elif choice==8:
    i=1
    fact=i
    for i in range(1,x+1):
        fact=fact*i
        i=i+1
    print("The factorial is :  ",fact)
elif choice==9:
    select=int(input("Enter the choice from above;  "))
    if select==1:
        print(" Mass of electron,Me = 9.1*10^-31 kg")
    elif select==2:
        print(" Mass of proton,Mp = 1.67*10^-27 kg")
    elif select ==3:
        print( " Boltzmann constant = 1.38*10^-23 J.s")
    elif select==4:
        print(" Charge on electron = 1.6*10^19 C")
    elif select==5:
        print(" Plank constant = 6.63*10^-34 J.s")
    elif select==6:
        print(" Speed of light = 3*10^8 m/s")
    elif select==7:
        print(" Mass of nuetron = 1.67*10^-27 kg")
    else :
        print("Wrong choice")
elif choice==10:
    list=[]
    a=int(input(" Enter the number :"))
    for j in range (1,a+1):
        
        if a%j==0:
            b=a%j
            list.append(b)

    if len(list)==2:
            print(" The number",a,"is prime ")
    else:
            print("The number",a,"is not prime")

else:
    print(" Wrong choice")