#include <iostream>
using namespace std;
class Base{
    public:
    Base(){
        cout<< "Default of Base" << endl;
    }
    Base(int a){
        cout<< "Parameterised of Base " << a<< endl;
    } 
};
class Derived : public Base{
    public:
    Derived(){
        cout << "Default of Derived"<< endl;
    }
    Derived(int a, int b): Base(a){
        cout<< "Parameterised of Derived " << b << endl;
    }

};
int main(){
    int a =10 ,b =20;
    Derived d(a, b);

    return 0;
}