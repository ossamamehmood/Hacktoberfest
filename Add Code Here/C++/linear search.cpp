#include<iostream>
using namespace std;
int main(){
	int n,key,i;
	int array[1000];
	cout<<"enter the no. of elements in an array:"<<endl;
	cin>>n;
	
	for(i=0;i<n;i++){
		cin>>array[i];
	}
	cout<<"enter the value you want to search"<<endl;
	cin>>key;
	for(i=0;i<=n-1;i++){
		if(array[i]==key){
			cout<<key<<" found at "<<i<<" position"<<endl;
			break;
		}
		
	}
		
	if(array[i]==n){
		cout<<" not found"<<endl;
	}
	return 0;
}
