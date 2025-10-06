class Calculator:
    def __init__(self):
        pass

    def add(self, a, b):
        return a + b

    def sub(self, a, b):
        return a - b

    def mult(self, a, b):
        return a * b

    def div(self, a, b):
        if b != 0:
            return a // b
        else:
            return "Division by zero is not allowed"

class Calculator:
    def __init__(self):
        self.calculator = Calculator()

    def display_menu(self):
        print("1. Addition")
        print("2. Subtraction")
        print("3. Multiplication")
        print("4. Division")

    def process_choice(self):
        while True:
            choice = int(input("Enter Choice (1-4): "))
            if choice in [1, 2, 3, 4]:
                a = int(input("Enter 1st number: "))
                b = int(input("Enter 2nd number: "))
                
                if choice == 1:
                    print(self.calculator.add(a, b))
                elif choice == 2:
                    print(self.calculator.sub(a, b))
                elif choice == 3:
                    print(self.calculator.mult(a, b))
                elif choice == 4:
                    print(self.calculator.div(a, b))
            else:
                print("Invalid choice. Exiting...")
                break


# Create an instance of the ZeroDay class and run the program
if __name__ == "__main__":
    Calculator = Calculator()
    Calculator.display_menu()
    Calculator.process_choice()
