#include<bits/stdc++.h>
using namespace std;
int SumofArray(int *arr,int n){

   if(n==0){
      return 0;
   }
   if(n==1){
      return arr[0];
   }
   int sum=arr[0]+SumofArray(arr+1,n-1);

   return sum;
}
int main(){
   int arr[]={1,2,3,4,5};
   int n=5;
   int ans=SumofArray(arr,n);
   cout<<"sum is: "<<ans<<" ";
}
