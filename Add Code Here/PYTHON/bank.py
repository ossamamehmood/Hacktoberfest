class BankAccount:
    def __init__(self, account_holder, balance=0.0):
        self.account_holder = account_holder
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            return f"Deposited ${amount}. New balance: ${self.balance}"
        else:
            return "Invalid deposit amount."

    def withdraw(self, amount):
        if amount > 0 and amount <= self.balance:
            self.balance -= amount
            return f"Withdrew ${amount}. New balance: ${self.balance}"
        else:
            return "Invalid withdrawal amount or insufficient balance."

    def get_balance(self):
        return f"Account balance for {self.account_holder}: ${self.balance}"

def main():
    print("Welcome to Simple Bank")
    account_holder = input("Enter your name: ")
    account = BankAccount(account_holder)

    while True:
        print("\nMenu:")
        print("1. Check Balance")
        print("2. Deposit")
        print("3. Withdraw")
        print("4. Exit")
        choice = input("Select an option (1/2/3/4): ")

        if choice == "1":
            print(account.get_balance())
        elif choice == "2":
            amount = float(input("Enter the deposit amount: $"))
            print(account.deposit(amount))
        elif choice == "3":
            amount = float(input("Enter the withdrawal amount: $"))
            print(account.withdraw(amount))
        elif choice == "4":
            print("Thank you for using Simple Bank. Goodbye!")
            break
        else:
            print("Invalid option. Please select a valid option.")

if __name__ == "__main__":
    main()
