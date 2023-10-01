#include <bits/stdc++.h>
using namespace std;

void NextGreaterIdx(int arr[],int n){
	// next greater element idx
	int ans[n];
	stack<int> s;
	ans[n-1]=-1;
	s.push(n-1);
	for(int i=n-2;i>=0;i--){
		while(!s.empty() && arr[s.top()]<=arr[i]){
			s.pop();
		}
		if(s.size()==0){
			ans[i]=-1;
		}
		else{
			ans[i]=s.top();
		}
		s.push(i);
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
}

int main(){
	int arr[]={100,80,60,70,60,75,85};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i = 0 ; i < n ;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	// next greater element
	int ans[n];
	stack<int> s;
	ans[n-1]=-1;
	s.push(arr[n-1]);
	for(int i=n-2;i>=0;i--){
		while(!s.empty() && s.top()<=arr[i]){
			s.pop();
		}
		if(s.size()==0){
			ans[i]=-1;
		}
		else{
			ans[i]=s.top();
		}
		s.push(arr[i]);
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	// next greater element idx
	NextGreaterIdx(arr,n);
	
	return 0;
}