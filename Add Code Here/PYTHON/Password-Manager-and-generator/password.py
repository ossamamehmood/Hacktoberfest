import random
import string
from queries import Queries


def store_psd(account, dom, psd):
    ch = input(f"Store account: {account} and password: {psd}? y/n ")
    if ch == 'y':
        query.insert(account, dom, psd)
    elif ch == 'n':
        print("password not stored")
        return
    else:
        print("wrong choice!")
        exit(0)


def storepsd():
    acc = input("Enter account ID: ")
    dom= input("Enter the domain: ")
    psd = input("Enter account password: ")
    cpsd = input(f"Re-enter password for {acc}:")
    if psd == cpsd:
        ch = input(f"Store account: {acc} and password: {psd}? y/n ")
        if ch == 'y':
            query.insert(acc, dom, psd)
        elif ch == 'n':
            print("password not stored")
            return
        else:
            print("wrong choice!")
            exit(0)
    else:
        print("password doesn't match, enter credentials again")
        storepsd()


def display():
    print("\nEnter 1 to view all passwords")
    print("Enter 2 to display password of a particular account")
    ch = int(input("enter your choice: "))
    if ch == 1:
        query.display1()
    elif ch == 2:
        acc = input("enter the account you want to view: ")
        query.display2(acc=acc)
    else:
        print("wrong choice, enter again!")
        display()


def genpsd():
    acc = input("Enter the account for which you want to generate password: ")
    dom = input("Enter the domain: ")
    num = int(input("Enter the length of the password (MAX-LENGTH = 10): "))
    password = "".join(random.choice(string.printable) for i in range(num))
    print(f"Generated password for {acc} is: {password}")
    store_psd(acc, dom, password)


def updatepsd():
    acc = input("Enter the account whose password needs to be changed: ")
    psd = input("enter current password: ")
    npsd = input("Enter new password: ")
    query.update(acc, psd)


query = Queries()
while True:
    print("\nEnter 1 to store new password")
    print("Enter 2 to show existing passwords")
    print("Enter 3 to generate and store password")
    print("Enter 4 to update password")
    print("Enter 0 to exit")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        storepsd()
        continue
    elif choice == 2:
        display()
        continue
    elif choice == 3:
        genpsd()
        continue
    elif choice == 4:
        updatepsd()
        continue
    elif choice == 0:
        query.close()
        exit(0)
    else:
        print("Wrong choice")
        query.close()
        break