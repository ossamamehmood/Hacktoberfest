#include <bits/stdc++.h>
#include<cmath>
using namespace std;
	
int main() {
	string s;
	string str,str1;
	cin>>s;
	for(int i=0;i<s.size()/2;++i){
		str.push_back(s[i]); 
	}
	for(int i=s.size()-1;i>=ceil((float)s.size()/2);--i){
		str1.push_back(s[i]);
	}
	if(str==str1){
		cout<<"Yes Palindrome";
	}else{
		cout<<"No not Palindrome";
	}
	return 0;
}