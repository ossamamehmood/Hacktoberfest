def factorial(n):
    return 1 if (n==1 or n==0) else n * factorial(n - 1);

number = int(input("Enter a number: "))
print("Factorial of " + str(number) + " is",
factorial(number))
# Ordinary-Droid
