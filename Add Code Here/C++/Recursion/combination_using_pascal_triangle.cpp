#include <iostream>
using namespace std;
int Comb(int n, int r){
    if(n==r || r== 0){
return 1;
    }
    else{
        return Comb(n-1, r-1) + Comb(n-1, r); 
    }
}
int main(){
    cout<< Comb(5,2);
    return 0;
}