#include <iostream>
using namespace std;
class Base{
    public:
    void display(){
        cout << "Base class"<< endl;
    }
};
class Derived : Base{
    public:
void display(int x){
        cout << "Derived class"<< endl;
    }
};

int main(){
    Derived d;
    d.display(10);
    return 0;
}