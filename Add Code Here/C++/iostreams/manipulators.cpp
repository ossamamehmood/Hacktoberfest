#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout << hex << right<< showbase << nouppercase;
    cout << (long long)245454.5454 << endl;
    return 0;
}