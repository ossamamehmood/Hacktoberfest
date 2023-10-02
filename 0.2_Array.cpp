//Take inputs from the user and print on the screen
#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "How many inputs you want " << endl;
    cin >> n;   // suppose n = 3
    
    cout << "Enter the inputs " << endl;
    int input[100];                  //store over here --> [10, 20, 30]
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];               // [10, 20, 30]
    }

    cout << "\nYour output is " << endl;

    for (int i = 0; i < n; i++)
    {
       cout << input[i] << endl;    // input[0,1,2] -->  10, 20, 30
    }
    
    
}