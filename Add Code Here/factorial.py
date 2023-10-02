
# Defining the function which accepts only one number
def factorial(num):
    if num == 0 or num == 1: #The factorial of one and zero is always one, hence we return one
        return 1
    else:
        return num * factorial(num - 1) # If the number is greater than one we will recursively call the function till we get 1.


print(factorial(5)) # finally we print the answer with a parameter, you can get user defined input as well.
