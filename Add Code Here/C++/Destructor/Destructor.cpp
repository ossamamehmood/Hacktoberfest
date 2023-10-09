#include <iostream>
using namespace std;
class Demo{
    public:
    Demo(){
        cout << "Demo created";
    }
    ~Demo(){
        cout  << "Demo Destructed";
    }
};
void fun(){
    Demo *p = new Demo();
    delete p;
}
int main(){
    fun();
    return 0;
}