from math import log10, sin, cos, tan, sqrt, factorial, radians
start = True
while start:
    q = input("Do you want to quit? (y/n) -> ")
    if q == 'y':
        start = False
        continue
    num1 = float(input("Enter first number: "))
    op = input("Operators (+, -, /, *, ^, !, log, sin, cos, tan, sqrt)\nEnter operator: ")
    if op in ('+', '-', '/', '*'):
        num2 = float(input("Enter second number: "))
    elif op == '^':
        num2 = int(input("(note: integer)\n exp: "))
    
    if op == "+":
        print(num1 + num2)
    elif op == '-':
        print(num1 - num2)
    elif op == "/":
        try:
            print(num1 / num2)
        except:
            print("Math Error")
    elif op == "*":
        print(num1 * num2)
    elif op == '^':
        print(int(pow(num1, num2)))
    elif op == '!':
        print(factorial(int(num1)))
    elif op == 'log':
        print(log10(num1))
    elif op == 'sin':
        print(sin(radians(num1)))
    elif op == 'cos':
        print(cos(radians(num1)))
    elif op == 'tan':
        print(tan(radians(num1)))
    elif op == 'sqrt':
        print(sqrt(num1))
    else:
        print("Invalid")










