#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "Account_challenge.h"
#include <memory>

using namespace std;
int main(){

    cout<<"Hello world"<<endl;

    Ledger Bank_ledge {"Sigma Corporation"};


    Account Account_1 {"Shakti Santosh Nayak","1234"};
    Account Account_2 {"Santosh Nayak","4444"};
    Savings_Account {"Reenakhi Santosh Nayak","3333",3};
    Bank_deposit(10000,Account_1);
    cout<<Account_1.Balance<<endl;

    Transfer(Account_1,Account_2,"1234",5000,Bank_ledge);
    Transfer(Account_1,Account_2,"1234",3000,Bank_ledge);


    cout<<Account_2.Balance<<endl;

    cout<<Bank_ledge.statements<<endl;
    

    cout<<funds<<endl;

    unique_ptr <Account> ptr_1=make_unique <Savings_Account>();

    // This are smart pointers and we dont need to care about freeing them that is automatically done

    







    return 0;
}