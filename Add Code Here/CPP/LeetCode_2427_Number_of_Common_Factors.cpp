#include<bits/stdc++.h>
using namespace std;

int commonFactors(int a, int b) {
        int d;
        int count=0;
        (a<b)?d=a:d=b;
        
        for(int i=1;i<=d;i++){
            if(a%i==0 && b%i==0) count++;
            else continue;
        }
        
        return count;
}

int main(){
int n1,n2;
cin>>n1>>>n2;
cout<<commonFactors(n1,n2)<<endl;
return 0;
}
