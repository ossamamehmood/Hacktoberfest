def add(num1, num2):
 return num1 + num2
 
def subtract(num1, num2):
 return num1 - num2
 
def multiply(num1, num2):
 return num1 * num2
 
def divide(num1, num2):
 return num1 / num2
 
def modulo(num1, num2):
 return num1 % num2
 
# Take input from the user
num1 = int(input("Enter first number: "))
operation = input("What you want to do(+, -, *, /, %):")
num2 = int(input("Enter second number: "))
 
result = 0
if operation == '+':
 result = add(num1,num2)
elif operation == '-':
 result = subtract(num1,num2)
elif operation == '*':
 result = multiply(num1,num2)
elif operation == '/':
 result = divide(num1,num2)
elif operation == '%':
 result = modulo(num1,num2)
else:
 print("Please enter: +, -, *, / or %")
 
print(num1, operation, num2, '=', result)
