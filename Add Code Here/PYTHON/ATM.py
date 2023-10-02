class Atm:

    counter=0
    def __init__(self):
        self.__pin = ""
        self.__balance = 0
        self.sno = Atm.counter
        Atm.counter+=1
        
        self.menu()
    
    def get_pin(self):
        return self.__pin
    
    def set_pin(self,new_pin):
        if type(new_pin) == str:
            self.__pin = new_pin
            print("Pin changed")
        else:
            print("Not allowed")

    def menu(self):
        user_input = input("""HEllo how would like to proceed ?\n1. Enter 1 to create pin\n2. Enter 2 to deposit\n3. Enter 3 to withdraw\n4. Enter 4 to check balance\n5. Enter 5 to exit\n""")
        if user_input == '1':
            self.create_pin()
        elif user_input == '2':
            self.deposit()
        elif user_input == '3':
            self.withdraw()
        elif user_input == '1':
            self.check_balance()
        else:
            print("Bye")

    def create_pin(self):
        self.__pin = input("Enter your pin : ")
        print("Pin set successfully")
    def deposit(self):
        temp = input("Enter your pin : ")
        if temp==self.__pin:
            amount = int(input("Enter your amount"))
            self.__balance += amount
            print("Deposit succesfull")
        else:
            print("Invalid pin")

    def withdraw(self):
        temp = input("Enter your pin : ")
        if temp==self.__pin:
            amount = int(input("Enter your amount"))
            if amount<=self.__balance:
                self.__balance -= amount
                print("Operation succesfull")
            else:
                print("Insufficent funds")
        else:
            print("Invalid pin")
    
    def check_balance(self):
        temp = input("Enter your pin : ")
        if temp==self.__pin:
            print("Balance :",self.__balance)
        else:
            print("Invalid pin")

sbi = Atm()
sbi.deposit()
sbi.check_balance()
sbi.withdraw()