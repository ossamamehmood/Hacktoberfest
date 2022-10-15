#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

bool isNumber_string(const string& s){
    int len = s.length();
    for(int i = 0; i<len; i++){
        if(s[i]<'0' || s[i]>'9')
            return false;
    }
    return true;
}


int main(){
    
    string ccNumber;
    
    
    cout<<endl<<"This Application Will Validate A Credit Card Number"<<endl;
    cout<<"You Can Enter exit Anytime To Quit"<<endl;
    
    while(true){
        
        cout<<"Please Enter A Credit Card Number To Validate : ";
        cin>>ccNumber;
        
        if(ccNumber == "exit" || ccNumber == "EXIT")
            break;
            
        else if(!isNumber_string(ccNumber)){
            cout<<"Invalid Input";
            continue;
        }
        
        int len1 = ccNumber.length();
        int double_even_sum = 0;
        
        
        // step 1 is to double every second digit , starting from the right. if it 
        // results in a two digit number,add both the digits to obtain a single digit number,
        // finally, sum all the answers to obtain 'double_even_sum'.
        
        for(int i = len1-2; i>=0; i=i-2){
            int db1 ((ccNumber[i] - 48) * 2);
            if(db1>9){
                db1 = (db1/10) + (db1%10);
            }
            double_even_sum +=db1;
        }
        
        
        // step 2 is to add every odd placed digit from the right to the value 'double_even_sum'
        
        
        for(int i = len1-1; i>=0; i=i-2){
            double_even_sum += (ccNumber[i] - 48);
        }
        
        
        // step 3 is to check if the final 'double_even_sum' is a multiple of 10.
        // if yes , then it is a valid credit card number otherwise it is not.
        
        
        cout<<(double_even_sum%10 == 0 ?"Valid" : "Invalid")<<endl;
        
        continue;
    }
    return 0;
}
