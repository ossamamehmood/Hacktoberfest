#include <iostream>
using namespace std;

int main(){
    int A[8] = {7,8,4,6,45,10,15,70}, max;
    max = A[0];
    for(auto x:A){
        if(max <= x){
            max =x;
        }
    }
    cout<< max;
    return 0;
}