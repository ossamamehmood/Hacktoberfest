#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int n,int target){
  int ans=0;
  int low=0;
  int high=n-1;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(arr[mid]==target){
      return arr[mid];
      }
    else if(arr[mid]>target){
      high=mid-1;
      }
    else{
      ans=arr[mid];
      low=mid+1;
      }
    }
  return ans;
  }
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    }
  int target;
  cin>>target;
  int ans=solve(arr,n,target);
  cout<<"floor of "<<target<<"element is "<<ans<<endl;
  return 0;
  }
