#include <bits/stdc++.h>
using namespace std;

long long int m=2021;

vector<long long> multi2(vector<long long> a,vector<long long> b){
    vector<long long> c;
    c.push_back((a[0])%m*(b[0])%m+(a[1])%m*(b[2])%m);
    c.push_back((a[0])%m*(b[1])%m+(a[1])%m*(b[3])%m);
    c.push_back((a[2])%m*(b[0])%m+(a[3])%m*(b[2])%m);
    c.push_back((a[2])%m*(b[1])%m+(a[3])%m*(b[3])%m);
    return c;
}

vector<long long> binaryExp(vector<long long> a,long long n){
    if(n==0){
        return {1,0,0,1};
    }
    else if(n==1){
        return {1, 1, 1, 0};
    }
    else{
        vector<long long> x=binaryExp(a,n/2);
        if(n%2){
            return multi2(multi2(x,x),a);
        }
        else{
            return multi2(x,x);
        }
    }
}

int main(){
    long long n;
    cin>>n;
    vector<long long> A=binaryExp({1,1,1,0},n-1);
    cout<<A[0];
}