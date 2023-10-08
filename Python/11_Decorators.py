# Any callable python object that is used to modify a function or a class is known as Decorators
# There are two types of decorators
# 1.) Fuction Decorators
# 2.) Class Decorators


# 1.) Nested function
# 2.) Function return function
# 3.) reference
# 4.) Function as parameter


''' Note:   Need to take a function as parameter
            Add functionality to the function
            Function need to return another function'''

# def outer ():
#     a = 3
#     def inner ():
#         b = 4
#         result = a +b
#         return result
#     return inner # Refrences to the inner funtion
#     # retun inner() # Returning the value of the function

# a = outer ()

# print (a)


# def function1():
#     print ("Hi, I am function 1")


# def function2():
#     print ("Hi, I am function 2")


# function1()
# function2()


# def function1():
#     print("Hi, I am function 1")


# def function2(func):
#     print ("Hi, I am function 2, and now I am calling function 1")
#     func()

# function2(function1)


# def str_lower(func):
#     def inner():
#         str1 = func()
#         return  str1.lower
#     return inner()

# @str_lower
# def print_str():
#     return ("GOOD MORNING")


# print(print_str())

# d = str_lower(print_str)

# print(d())


# def add(func):
#     def sum():
#         result = func() + 5
#         return result
#     return sum


# @add
# def function1():
#     x = 3
#     y = 5
#     return x + y


# print(function1())

# print (add(function1()))


# Parameteric Decorator

def d(func):
    def inner(x, y):
        result = f'Answer of divide and the value of the a : {x} b : {y} \nResult is {func(x, y)}'
        return result
    return inner

@d
def div(a, b):
    divide = a // b
    return divide


print (div(4, 2))