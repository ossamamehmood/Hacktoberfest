#include<iostream>
using namespace std;
int main()
{
  int a,b,temp;
  cout<<"Enter 2 numbers\n";
  cin>>a>>b;
  cout<<"          MENU           \n";
  cout<<"Press 1. for Addition\nPress 2. for Subtraction\nPress 3. for Division\nPress 4. for Multiplpcation\n";
  cin>>temp;
  switch(temp)
  {
    case 1: cout<<"Result :"<<a+b;
    break;
    case 2: cout<<"Result :"<<a-b;
    break;
    case 3: cout<<"Result :"<<a/b;
    break;
    case 4: cout<<"Result :"<<a*b;
    break;
    default: cout<<"Invalid operation\n";
  }
}
