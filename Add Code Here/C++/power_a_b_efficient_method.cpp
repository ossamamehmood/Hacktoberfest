#include<bits/stdc++.h>
using namespace std;

int power(int a, int b){

    if(b == 0) return 1;
    if( b == 1) return a;

    int ans = power(a,b/2);

    if(b%2 == 0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}

int main(){

    int a, b;
    cout<<"Enter the base = ";
    cin>>a;
    cout<<"Enter the power = ";
    cin>>b;

    int ans = power(a,b);

    cout<<endl<<a<<" to the power "<<b<<" = "<<ans<<endl;

    return 0;
}