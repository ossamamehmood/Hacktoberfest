# Function to add two numbers
def add(x, y):
    return x + y

# Function to subtract two numbers
def subtract(x, y):
    return x - y

# Function to multiply two numbers
def multiply(x, y):
    return x * y

# Function to divide two numbers
def divide(x, y):
    # Check if the denominator is not zero
    if y != 0:
        return x / y
    else:
        return "Error: Division by zero is not allowed."

# Main function
def main():
    print("Calculator Menu:")
    print("1. Addition (+)")
    print("2. Subtraction (-)")
    print("3. Multiplication (*)")
    print("4. Division (/)")

    # Get operator choice from the user
    choice = input("Enter operator (1/2/3/4): ")

    # Get two numbers from the user
    num1 = float(input("Enter first number: "))
    num2 = float(input("Enter second number: "))

    # Perform calculation based on the operator choice
    if choice == '1':
        print("Result: ", add(num1, num2))
    elif choice == '2':
        print("Result: ", subtract(num1, num2))
    elif choice == '3':
        print("Result: ", multiply(num1, num2))
    elif choice == '4':
        print("Result: ", divide(num1, num2))
    else:
        print("Invalid operator choice.")

# Run the calculator program
if __name__ == "__main__":
    main()
