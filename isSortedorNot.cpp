#include<bits/stdc++.h>
using namespace std;
bool isSortedorNot(int *arr,int n){

   if(n==0 || n==1)return true;
   if(arr[0]>arr[1])return false;
   else{
      return isSortedorNot(arr+1,n-1);
   }
}
int main(){
   int arr[]={1,2,3,4,5,7,6};
   int n=7;
   bool ans=isSortedorNot(arr,n);
   if(ans)
   {
      cout<<"SORTED"<<endl;
   }else{
      cout<<"NOT SORTED"<<endl;
   }


}
