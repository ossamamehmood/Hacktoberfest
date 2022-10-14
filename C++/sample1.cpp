#include <bits/stdc++.h>
using namespace std;

int main() {
    long long mysol;
    cin>>mysol;
    while (mysol--)
    {
        long long n,x;
        cin>>n>>x;
        
        if(n>x)
        {
            if((n-x)%4==0)
            cout<<(n-x)/4<<endl;
            else
            cout<<((n-x)/4)+1<<endl;
        }
       else
       cout<<0<<endl;
    }
	return 0;
}
