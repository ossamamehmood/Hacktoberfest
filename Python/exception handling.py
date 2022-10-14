# Develop a Python program to understand working of exception handling.


# Exception handling example
try:
    a = int(input("Enter a number: "))
    b = int(input("Enter another number: "))
    c = a/b
    print(c)
except ZeroDivisionError:
    print("Division by zero is not possible")
except ValueError:
    print("Invalid input")
except Exception as e:
    print(e)
else:
    print("No exceptions")
finally:
    print("This is finally block")