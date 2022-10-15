#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;



int main(){
    
    cout << "Enter first number : " << flush;
    int num1;
    cin >> num1;
    
    cout << "Enter second number : " << flush;
    int num2;
    cin >> num2;
    
    cout << "CALCULATOR" << endl;
    cout << "1.Add" << endl;
    cout << "2.Subtract" << endl;
    cout << "3.Divide" << endl;
    cout << "4.Multiply" << endl;
    
   
    
    cout << "Which operation do you want to perform (select a number from above given options) : " << flush;
    int option;
    cin >> option;
    
    switch(option){
    case 1:
        cout << "Adding given numbers..." << endl;
        cout <<"Result = " << num1+num2 << endl;
        break;
        
    case 2:
        cout << "Subtracting given numbers..." <<endl;
        cout <<"Result = " << num1 - num2<<endl;
        break;
        
    case 3:
        cout << "Dividing given numbers..." <<endl;
        cout <<"Result = " << (float)num1/num2 <<endl;
        break;
        
    case 4:
        cout << "Multiplying given numbers..." <<endl;
        cout <<"Result = " << num1*num2 <<endl;
        break;
        
    default:
        cout << "INVALID INPUT" << endl;
    }

    return 0;

}


