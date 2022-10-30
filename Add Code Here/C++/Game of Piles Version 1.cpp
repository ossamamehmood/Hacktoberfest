#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long n,r = 0;
	    cin>>n;
    	vector<long long> v(n);
    	for(int i=0;i<n;i++)
    	{
    	    long long x;
    	    cin>>x;
    	    v.push_back(x);
    	    r = r + x;
    	}
    	if(find(v.begin(),v.end(),1) != v.end() || r%2)
    	cout<<"Chef"<<endl;
    	else
    	cout<<"Chefina"<<endl;
    	
    	    
    	}
    	return 0;
	}
