#include<bits/stdc++.h>
using namespace std;
int main(){

	map<char,int> mp;
	mp['I']=1;
	mp['V']=5;
	mp['X']=10;
	mp['L']=50;
	mp['C']=100;
	mp['D']=500;
	mp['M']=1000;

	string q="MCMXCIV";
	int ans=0;	
	int n=q.length();

	int result=mp[q[n-1]];

	for (int i =q.length()-2; i >=0; i--)
	{
		if(mp[q[i]]<mp[q[i+1]]){
			result-=mp[q[i]];
		}else{
			result+=mp[q[i]];
		}
	}
	// return result;
	cout<<result;
	







	

	


}