#include<iostream>
using namespace std;


int main() {
    
    int n,k,i,j;
    cin >> n;
    for(i = 1; i<=(n+1)/2;i++){
        for(j = 1; j<=((n+1)/2)-i;j++)
            cout << ' ';
        for(k = 1; k<=2*i-1;k++)
            cout << '*';
        cout << endl;
    }
    for(i = (n-1)/2; i>=1;i--){
        for(j = 1; j<=((n-1)/2)-i+1;j++)
            cout << ' ';
        for(k = 1; k<=2*i-1;k++)
            cout << '*';
        cout << endl;
    }
    
}