#include <bits/stdc++.h>
using namespace std;

long int clique(int n,long long int e){
    double temp=0;
    int d=1;
    while(e>temp && d<n){
        temp = ((double)(1-1/d))*e*e/2;
        d++;
    }
    if(d==n)
    d-=1;
    return d;
}


int main() {
    int t;
    cin >> t;
    while(t!=0){
        int n;long long int m;
        cout<<"Enter n and m: "<<endl;
        cin >> n >> m ;
        if(m!=n*(n-1)/2)
        cout <<"d= "<< clique(n,m) << endl;
        else 
            cout <<"d= "<< n << endl;

        t--;
    }
    return 0;
}