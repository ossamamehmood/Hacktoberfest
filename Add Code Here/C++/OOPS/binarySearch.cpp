#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int binarysearch(int arr[],int n,int k){
		int count=0;
		for(int i=0; i<n; i++){
			if(arr[i]!=k){
				count++;
			}
			if(arr[i]==k){
				break;
			}
		}
		cout<<count<<endl;
	}
};
int main(void){
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		int arr[N];
		for(int i=0; i<N; i++){
			cin>>arr[i];
		}
		int key;
		cin>>key;
		Solution ob;
		int found = ob.binarysearch(arr,N,key);
		cout<<found<<endl;
	}
}
