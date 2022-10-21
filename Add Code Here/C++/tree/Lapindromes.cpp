#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
	string str1;
	cin>>str1;
	string s1,s2;
	int len=str1.size();
	s1=str1.substr(0,len/2);
	if((len%2)!=0)
	{
		s2=str1.substr(len/2+1,len-1);
	}
	else
	{
		s2=str1.substr(len/2,len-1);
	}	
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	if(s1==s2)
	{
		cout<<"YES"<<endl;
	}
	else{
	cout<<"NO"<<endl;	
	}	
	}
	
return 0;
}
