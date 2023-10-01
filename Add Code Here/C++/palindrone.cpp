#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"PLEASE ENTER THE LENGTH OF WORD (FOR WHICH YOU WANT TO CHECK PALINDRONE PROPERTY) : "<<endl;
    cin>>n;
    char a[n+1];
    char arr;
    cout<<"PLEASE ENTER THE WORD (FOR WHICH YOU WANT TO CHECK PALINDRONE PROPERTY) : "<<endl;
    cin>>a;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=a[n-1-i])
        {
            cnt=1;
            break;
        }
    }
    if(cnt==1){
        cout<<"not a palindrone";
    }
    else{
        cout<<"palindrone";
    }
    return 0;
}