#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string accNumber, string accHolder, double initialBalance)
        : accountNumber(accNumber), accountHolder(accHolder), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into account " << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    void display() const {
        cout << "Account Information:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    string getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    vector<BankAccount> accounts;

    while (true) {
        cout << "Bank Account System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account Information" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string accNumber, accHolder;
                double initialBalance;

                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, accHolder);
                cout << "Enter initial balance: ";
                cin >> initialBalance;

                BankAccount newAccount(accNumber, accHolder, initialBalance);
                accounts.push_back(newAccount);

                cout << "Account created successfully!" << endl;
                break;
            }
            case 2: {
                string accNumber;
                double amount;

                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter deposit amount: ";
                cin >> amount;

                for (BankAccount &account : accounts) {
                    if (account.getAccountNumber() == accNumber) {
                        account.deposit(amount);
                        break;
                    }
                }
                break;
            }
            case 3: {
                string accNumber;
                double amount;

                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                for (BankAccount &account : accounts) {
                    if (account.getAccountNumber() == accNumber) {
                        account.withdraw(amount);
                        break;
                    }
                }
                break;
            }
            case 4: {
                string accNumber;

                cout << "Enter account number: ";
                cin >> accNumber;

                for (const BankAccount &account : accounts) {
                    if (account.getAccountNumber() == accNumber) {
                        account.display();
                        break;
                    }
                }
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
