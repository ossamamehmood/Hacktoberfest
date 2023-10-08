# Local scope

def func1():
    v = 1  # local scope

    print("I am local variable v : ", v)


func1()


# Global Scope

y = 10  # Global scope


def func2():
    x = 20

    print("I am local variable x : ", x)


func2()
print("I am global variable y : ", y)


# Enclose Scope

a = 1  # Global Scope


def outer():
    b = 2  # Enclose scope

    def inner():
        c = 3  # Local variable
        print("I am Enclose variable b : ", b)  # Enclose scope
        print("I am local variable c : ", c)  # local scope
    print("I am Enclose variable b : ", b)  # Enclose scope
    inner()  # inner function


outer()


# What if the all the variable names are same then which variable function show in the output?

# eg.

a = 22

def f1 ():
    a = 33
    def f2():
        a = 45
        print ("a : ", a)
    f2()

f1()


# LEGB rule Local --> Enclosed --> Global --> Built - in 