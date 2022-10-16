#include<bits/stdc++.h>
using namespace std;

//int F[10];
int fib(int n){

if(n<=1)
return n;

return fib(n-2) + fib(n-1);
// if(n<=1){
//     F[n] = n;

//     return n;
// }
// else{
//     if(F[n-2]==-1)
//     F[n-2]=fib(n-2);

//     if(F[n-1]==-1)
//     F[n-1] = fib(n-1);

// return F[n-2] + F[n-1];
// }

}
int main(){

    cout<<fib(7);
    //cout<<r<<endl;

return 0;
}
