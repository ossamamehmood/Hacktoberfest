#include <bits/stdc++.h>
using namespace std;

void sieve(int a, int b){
    vector<bool> arr(b,true);
    
    for(int i=2; i*i<=b; i++) //i*i=n is equal to i=sqrt(n)
    {
        for(int j=2*i; j<b; j+=i){
            if(arr[j]==true){
                arr[j]=false;
            }
        }
    }
    
    for(int i=2; i<b; i++){
        if(arr[i]==true)
        cout<<i<<endl;
    }
}

int main() {
    int a, b;
    cin>>a>>b;
    sieve(a,b);
    

    return 0;
}
