#include<bits/stdc++.h>
using namespace std;

int power(int a, int b){

    if(b == 0) return 1;

    int ans = a*power(a,b-1);

    return ans;
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