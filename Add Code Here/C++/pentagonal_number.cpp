// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int ans=0,flag=0;
    int diff=1;
    

    while(ans<n){
        ans=ans+diff;
        diff+=3;
       
        if(ans==n){
            cout<<"It's a pentagonal number";
            flag=1;
        }
    }
    
    if(flag==0){
        cout<<"Not a pentagonal number";
    }

    return 0;
}