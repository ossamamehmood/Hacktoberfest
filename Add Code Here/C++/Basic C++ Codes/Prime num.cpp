#include <bits/stdc++.h>
using namespace std;

bool prime(int n)
{
	if(n<=1)
	return false;
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}
int main()
{
	int n;
	cout<<"Enter the num"<<endl;
	cin>>n;
	bool a;
	a=prime(n);
	if(a==true)
	cout<<"It is prime";
	else
	cout<<"It is not prime";
}
