#include <bits/stdc++.h>

#define MIN_BALANCE 500

using namespace std;

// class of insufficient_balance will be used as throw for an exception
class Insufficient_Balance{};

// individual account class
class Account{

private:

    // class members 
    int account_number;
    string first_name;
    string last_name;
    float balance;
    static int next_account_number;

public:

    // constructors
    Account(){}
    
    Account(string f_name, string l_name, float bal);
    
    // small functions required to access each account's individual information
    int get_acc_num(){
        return account_number;
    }

    string get_first_name(){
        return first_name;
    }

    string get_last_name(){
        return last_name;
    }

    float get_balance(){
        return balance;
    }
 
    // necessary functions for an individual account
    void Deposit(float amount);
    void Withdraw(float amount);
    static void set_last_acc_num(int account_number);
    static int get_last_acc_num();

    // functions to read, write and display from a file
    friend ifstream & operator >> (ifstream &ifs, Account &acc);
    friend ofstream & operator << (ofstream &ofs, Account &acc);
    friend ostream & operator << (ostream &os, Account &acc);
};

// initializing the next_account_number
int Account::next_account_number = 0;

// bank i.e. containing information of every account registered
class Bank{

private:

    // class members
    map <int, Account> accounts;

public:

    // constructor
    Bank();
    
    // necessary functions for collection of accounts
    Account open_account(string f_name, string l_name, float bal);
    void close_account(int account_number);
    Account Deposit(int account_number, float amount);
    Account Withdraw(int account_number, float amount);
    Account Balance_Enquiry(int account_number);
    void Show_all_accounts();
    
    // destructor
    ~Bank();
};

int main(){

    Bank b;
    Account acc;

    int choice;
    string fname, lname;
    int account_number;
    float balance;
    float amount;

    cout << "*****Banking System*****" << endl;
    do {

        cout << "\nSelect one option below ";
        cout << "\n1 Open an Account ";
        cout << "\n2 Balance Enquiry ";
        cout << "\n3 Deposit ";
        cout << "\n4 Withdraw ";
        cout << "\n5 Close an Account ";
        cout << "\n6 Show all Accounts ";
        cout << "\n7 Quit ";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter First Name: ";
                cin >> fname;
                cout << "Enter Last Name: ";
                cin >> lname;
                cout << "Enter initial balance: ";
                cin >> balance;

                acc = b.open_account(fname, lname, balance);
                cout << endl << "Congratulations account is created " << endl;
                cout << acc;
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> account_number;
                acc = b.Balance_Enquiry(account_number);
                cout << endl << "Your Account Details " << endl;
                cout << acc;
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> account_number;
                cout << "Enter Balance: ";
                cin >> amount;
                acc = b.Deposit(account_number, amount);
                cout << endl << "Amount is deposited " << endl;
                cout << acc;
                break;
            
            case 4:
                cout << "Enter Account Number: ";
                cin >> account_number;
                cout << "Enter Balance: ";
                cin >> amount;
                acc = b.Withdraw(account_number, amount);
                cout << endl << "Amount is withdrawn " << endl;
                cout << acc;
                break;

            case 5:
                cout << "Enter Account Number: ";
                cin >> account_number;
                b.close_account(account_number);
                cout << endl << "Account is Closed " << endl;
                cout << acc;

            case 6:
                b.Show_all_accounts();
                break;

            case 7:
                break;

            default:
                cout << "\nEnter correct choice: ";
                exit(0);
        }
    } while (choice != 7);

    return 0;
}

// member functions of class Account
Account::Account (string f_name, string l_name, float bal){
    
    next_account_number++;
    account_number = next_account_number;
    first_name = f_name;
    last_name = l_name;
    balance = bal;
}

void Account::Deposit(float amount){

    balance += amount;
}

void Account::Withdraw(float amount){
    
    if (balance-amount < MIN_BALANCE){
        throw Insufficient_Balance();
    }

    balance -= amount;
}

void Account::set_last_acc_num(int account_number){

    next_account_number = account_number;
}

int Account::get_last_acc_num(){

    return next_account_number;
}

// read, write and display from a file's functions

ifstream & operator>>(ifstream &ifs, Account &acc){

    ifs >> acc.account_number;
    ifs >> acc.first_name;
    ifs >> acc.last_name;
    ifs >> acc.balance;

    return ifs;
}

ofstream & operator<<(ofstream &ofs, Account &acc){

    ofs << acc.account_number << endl;
    ofs << acc.first_name << endl;
    ofs << acc.last_name << endl;
    ofs << acc.balance << endl;

    return ofs;
}

ostream & operator<<(ostream &os, Account &acc){

    os << "First Name: " << acc.get_first_name() << endl;
    os << "Last Name: " << acc.get_last_name() << endl;
    os << "Account No.: " << acc.get_acc_num() << endl;
    os << "Balance: " << acc.get_balance() << endl;

    return os;
}

// bank main functions

Bank::Bank(){

    Account account;
    ifstream infile;
    infile.open("Bank.data");

    if (!infile.eof()){

        infile >> account;
        accounts.insert(pair<long, Account>(account.get_acc_num(), account));
    }
    Account::set_last_acc_num(account.get_acc_num());

    infile.close();
}

// bank member functions

Account Bank::open_account(string fname, string lname, float balance){

    ofstream outfile;
    Account account(fname, lname, balance);
    accounts.insert(pair<int, Account>(account.get_acc_num(), account));
    
    outfile.open("Bank.data", ios::trunc);

    map<int, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++){
        outfile << itr->second;
    }
    outfile.close();

    return account;
}

Account Bank::Balance_Enquiry(int account_number){

    map <int, Account>::iterator itr = accounts.find(account_number);
    
    return itr->second;
}

Account Bank::Deposit(int account_number, float amount){

    map <int, Account>::iterator itr = accounts.find(account_number);
    itr->second.Deposit(amount);

    return itr->second;
}

Account Bank::Withdraw(int account_number, float amount){

    map <int, Account>::iterator itr = accounts.find(account_number);
    itr->second.Withdraw(amount);

    return itr->second;
}

void Bank::close_account(int account_number){

    map <int, Account>::iterator itr = accounts.find(account_number);
    cout << "Account Deleted" << itr->second;

    accounts.erase(account_number);
}

void Bank::Show_all_accounts(){

    map <int, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++){
        cout << "Account " << itr->first << endl << itr->second << endl;
    }
}

Bank::~Bank(){

    ofstream outfile;
    outfile.open("Bank.data", ios::trunc);

    map<int, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++){
        outfile << itr->second;
    }

    outfile.close();
}