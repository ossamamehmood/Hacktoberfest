#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning/

bool isPalindrome(string s,int start,int end){
	
	while(start<end){
		
		if(s[start++]!=s[end--])
			return false;
		
	}
	
	return true;
	
}

void solve(int index,string s,vector<vector<string>> & ans,vector<string> path){
	
	if(index==s.size()){
		ans.push_back(path);
		return ;
	}
	
	for(int i=index;i<s.size();i++){
		
		if(isPalindrome(s,index,i)){
			
			string t = s.substr(index,i-index+1);
			path.push_back(t);
			solve(i+1,s,ans,path);
			path.pop_back();
			
		}
		
	}
	
	
}
vector<vector<string>> partition(string s) {
	
	vector<vector<string>> ans;
	vector<string> path;
	solve(0,s,ans,path);
	return ans;
}

int main()
{
	vector<int> v;
	
}