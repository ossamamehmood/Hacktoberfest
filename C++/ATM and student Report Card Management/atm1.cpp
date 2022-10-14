#include <iostream>
using namespace std;

void showMenu() {
	cout<<"*********Menu************" << endl;
	cout<<"1. Check Balance" << endl;
	cout<<"2. Deposite" << endl;
	cout<<"3. Withdrawl" << endl;
	cout<<"4. Money Transfer" << endl;
	cout<<"5. Exit" << endl;
	cout<<"**************************"<< endl;
}

int main ()
{
	//check balance, deposite, withdraw, show menu,transfer money
	int option;
	double balance = 5000;
	
	do{
	showMenu();
	cout<<"option:";
	cin>>option;
	system("cls");
	
	switch(option){
		case 1: cout<<"Balance is:" << balance << "$"<< endl; break;
		case 2: cout<<"Deposite Amount:";
		    double depositeAmount;
		    cin>> depositeAmount;
		    balance+= depositeAmount;
		    cout<<"Total Amount:"<< balance <<endl;
		    break;
		case 3: cout<<"Widthdraw Amount:";
		    double withdrawAmount;
		    cin>> withdrawAmount;
		    if (withdrawAmount <= balance)
		        balance-= withdrawAmount;
		    else
			    cout<< "Not Enough Money" << endl;
			cout<<"Total Amount:"<< balance <<endl;    
			break;  
		case 4: cout<<"Transfer Amount:";
		    double transferAmount;
		    cin>> transferAmount;
		    if (transferAmount <= balance)
		        balance-= transferAmount;
		    else
			    cout<< "Not Enough Money" << endl;
			cout<< "Enter Account Number";
		    double accountnumber;
		    cin>> accountnumber;
		    cout<<"Transfer Successfully" << endl; 
		    cout<<"Total Amount:"<< balance <<endl;
			break;  
	}
	cout<< "******Thankyou Soo Much, Have A Nice Day********"<< endl;
	
    } while(option!=5);
	
	system("pause>0");
	
}
