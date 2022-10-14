//KAMYAVERMA
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    int i=1;
    while( i<=n){
        int j=1+n-i;
        int count=1;
        while(j>0){
            cout<<count;
            count++;
            j--;
        }
        int star=(i-1)*2;
        while(star>0){
            cout<<"*";
            star--;
        }
        int k=1+n-i;
        while(k>0){
            cout<<k;
            k--;
        }
    cout<<endl;
    i++;
    }
}


/*
OUTPUT:
enter the number
5

1234554321
1234**4321
123****321
12******21
1********1
*/
