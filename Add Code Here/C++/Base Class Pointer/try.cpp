#include <iostream>
using namespace std;
class Base{
    public:
    void f1(){
        cout<< "Function of base class"<< endl;
    }
};
class Derived: public Base{
    public:
    void f2(){
        cout<< "Function of Derived class"<< endl;
    }
};
void demo(){
    cout<<"chal chaL ave "<< endl;
    demo();
}
int main(){
    Derived b;
    Base *p = &b;
    // p->f1();
    // p->f2();
    demo();
    return 0;
}