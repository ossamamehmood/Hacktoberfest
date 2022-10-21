#include<iostream>
using namespace std;
void dnf_sort(int a[],int n){
	//sort the array of 0's , 1's and 2's
	//initially
	int low=0;
	int high=n-1;
	int mid=0;
	while(mid<=high){
		if(a[mid]==0){
			swap(a[mid],a[low]);
			low++;
			mid++;
		}
		else if(a[mid]==1){
			mid++;
		}
		else if(a[mid]==2){
			swap(a[mid],a[high]);
			high--;
			
		}
	}
	return;
	
}
int main(){
	int n;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dnf_sort(a,n);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
