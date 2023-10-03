def factorial(number):
    if number == 0:
        return 1
    else:
        return number * factorial(number - 1)


N = int(input("Enter N: "))
result = factorial(N)
print(f"The factorial of {N} is {result}")
