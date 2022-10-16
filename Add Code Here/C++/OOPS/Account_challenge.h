#include <iostream>
#include <string>

using namespace std;


#ifndef _ACCOUNT_CHA_H_
#define _ACCOUNT_CHA_H_

double funds=1000000000000000.0;





class Account{
    static constexpr const char* Company_Name="Sigma";

    protected:
    int pin_attempts;
    public:
    string Name;
    double Balance;
    string pin;



    Account(string name_="New Account",string pin_="0000"):Name{name_},pin{pin_},pin_attempts{3}{
        cout<<"Dear "<<name_<<" ! Your Account is Successfully Created with the pin you requested. Enjoy Transactions with "<<Company_Name<<" !"<<endl;

    }

    void deposit(double amount){

        Balance+=amount;
        cout<<Balance<<" Successfully deposited to "<<Name<<endl;

    }
    bool Withdraw(double amount,string pin_){

        if(pin_==pin){
            if (Balance>=amount) {
            Balance-=amount;
            return true;
            }
            else {
            cout<<"Insufficient Balance"<<endl;
            return false;
            }
            
        }
        else {
            pin_attempts--;
            cout<<"Incorrect Pin entered"<<endl;
            cout<<"You are left with "<<pin_attempts<<" attempts"<<endl;
            return false;
            }

    }
    
    void change_Name(string pin_,string name_){
        if (pin_==pin) {
            Name=name_;
            cout<<"Your Name is Successfully changed"<<endl;
            
        }

        else {
            cout<<"Request Failed ! Incorrect Pin entered"<<endl;
        }
    }

    void change_pin(string curr_pin_,string new_pin_){
        if(curr_pin_==pin){
            pin=new_pin_;
            cout<<"Pin is successfully changed"<<endl;
        }

        else {
            cout<<"The entered current pin is wrong \n";
        }


    }



};



class Ledger{
    string Name;
    public:
    string statements;
    Ledger(string Company_Name):Name{Company_Name},statements{""}{}

    bool add_statement(const Account &depositer, const Account &receiver,double amount){
        statements+=depositer.Name+" -> "+receiver.Name+" : "+to_string(amount)+"\n";
        return true;
    }

    
    

};







void Transfer(Account &depositer,Account &receiver,string deposieter_pin,double amount,Ledger &ledge,string type="Customer"){
    
    if(depositer.Withdraw(amount,deposieter_pin)) {

            if(type=="Customer"){
            funds+=amount*(0.005);
            cout<<"Transaction costs : "<<amount*(0.005)<<endl;
            amount-=amount*(0.005);
            }
            receiver.deposit(amount);
            cout<<amount<<"$ Successfully transfered from "<<depositer.Name<<"'s Account to "<<receiver.Name<<"'s Account\n";
            ledge.add_statement(depositer,receiver,amount);
        
    }
    else{
        cout<<"You have entered the incorrect pin\n";
    }

}





class Savings_Account:public Account{
    friend void Transfer(Account &depositer,Savings_Account &receiver,string deposieter_pin,double amount,Ledger &ledge);
protected:
double int_rate;
public:
Savings_Account(string name_="New Account",string pin_="0000",double int_rate_=0.0) :Account(name_,pin_),int_rate{int_rate_}{}
};


void Transfer(Account &depositer,Savings_Account &receiver,string deposieter_pin,double amount,Ledger &ledge){
    if(depositer.Withdraw(0,deposieter_pin)){
        funds-=amount*(receiver.int_rate);
        receiver.deposit(amount*(receiver.int_rate));
        
        }
    else return;
    Transfer(depositer,receiver,deposieter_pin,amount,ledge);
}



void Bank_deposit(double amount,Account &receiver){

    funds-=amount;
    receiver.deposit(amount);

}





#endif