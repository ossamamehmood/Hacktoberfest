#include <iostream>
using namespace std;
int ptr(){
    return 10;
}
int main(){
    int   *p;
    p = new int[20];
    int *q = &p[2];
    int d = q -p;
    cout << p -2;
    return 0;
}