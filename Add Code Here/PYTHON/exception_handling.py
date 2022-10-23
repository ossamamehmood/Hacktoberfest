"""
    Created By : Vikram Markali
"""
from decimal import DivisionByZero


print("start...")

try:
    x = int(input("Enter first number:"))
    y = int(input("Enter second number:"))
    c = x / y
    print(c)
    
except ZeroDivisionError as e:      #same like catch{} block in java....
    print('Error:',e)

except ValueError as e:
    print('Error:',e)

except Exception as e:
    print('Some other exception occured:',e)   

finally:
    print('end...')