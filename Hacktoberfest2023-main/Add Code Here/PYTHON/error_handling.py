'''
@Author: hariom09090
'''

try:
    # Prompt the user for input
    num1 = input("Enter a numerator: ")
    num2 = input("Enter a denominator: ")

    # Validate the inputs
    if not num1.isdigit() or not num2.isdigit():
        raise ValueError("Both numerator and denominator must be integers.")

    # Convert the inputs to integers
    num1 = int(num1)
    num2 = int(num2)

    # Perform the division
    result = num1 / num2

except ValueError as ve:
    # Handle the case when the user enters a non-integer
    print(f"ValueError: {ve}")

except ZeroDivisionError as ze:
    # Handle the case when the user enters 0 as the denominator
    print("ZeroDivisionError: Cannot divide by zero.")

except Exception as e:
    # Handle other unexpected exceptions
    print(f"An unexpected error occurred: {e}")

else:
    # Code to execute if no exceptions are raised
    print(f"Result: {result}")

finally:
    # Code that always runs, regardless of exceptions
    print("Execution finished.")
