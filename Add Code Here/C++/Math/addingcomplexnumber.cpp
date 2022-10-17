#include <iostream>
#include <cmath>
using namespace std;

int main(){

    cout<<"\nTo enter a the complex number a + bi, enter 'a' add a space and then enter 'b'\n"<<endl;
      
    float x,y,z,t;
    cout<<"say x and y ";
    cin>>x>>y;
    cout<<"Your 1st complex number is "<< x <<" + "<< y<<"i"<<endl;

    cout<<"say z and t ";
    cin>>z>>t;
    cout<<"Your 2st complex number is "<< z <<" + "<< t<<"i\n"<<endl;

    cout<<"Sum of both numbers is "<< x+z <<" + "<< y+t<<"i";



    return 0;
}
