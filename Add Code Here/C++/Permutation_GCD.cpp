#include <iostream>
using namespace std;

int main() {
    
	int tt;
	cin>>tt;
	while(tt--)
	{
	    int n,x;
	    cin>>n>>x;
	    if(x<n)
	    {
	        cout<<"-1"<<endl;
	    }
	    else
	    {
	        int p=x-n+1;
	        cout<<p<<" ";
	        for(int i=1;i<=n;i++)
	        {
	            if(i!=p)
	            cout<<i<<" ";
	            
	        }
	        cout<<endl;
	        
	    }
	}
	
	return 0;
}
