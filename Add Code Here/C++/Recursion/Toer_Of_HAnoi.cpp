#include <iostream>
using namespace std;
void Hanoi(int n, int A, int B, int C){
    if(n>0){
        Hanoi(n-1, A, C, B);
        cout  << A << " to " << C << endl;
        Hanoi(n-1, B,A, C);
    }
}
int main(){
    Hanoi(3, 1,2,3);
    return 0;
}