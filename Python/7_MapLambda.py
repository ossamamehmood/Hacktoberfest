# In Python, an anonymous function means that a function is without a name. As we already know that the def keyword is used to define a normal function in Python. Similarly, the lambda keyword is used to define an anonymous function in Python. This is also use as one line of code

# Normal Def function

def cube(y):
    return y * y * y

# lambda function

lambda_cube = lambda y : y*y*y

print(cube(2))
print(lambda_cube(2))




# map() function returns a map object(which is an iterator) of the results after applying the given function to each item of a given iterable (list, tuple etc.)

# map(fun, iter)

def add(x, y):
    return x + y

num = (1, 2, 3, 5)
num1 = (1, 2, 3, 5)

sum = map(add, num1, num)
print(list(sum))