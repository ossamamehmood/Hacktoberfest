#include <iostream>

using namespace std;

int main()
{
    //pointer
    int a=3;
    int* b=&a;
    cout<<"The value of a is "<<a<<endl; 
    cout<<"The value at address b is "<<*b<<endl; 
    cout<<"The address of a is "<<b<<endl; 
    cout<<"The address of a is "<<&a<<endl; 


    // pointer to pointer 

    int** c =&b;
    cout<<"The address of b is "<<&b<<endl; 
    cout<<"The address of b is "<<c<<endl; 
    cout<<"The value at address c "<<*c<<endl; 
    cout<<"The value at address value_at(value_at(c))"<<**c<<endl; 
    return 0;
}