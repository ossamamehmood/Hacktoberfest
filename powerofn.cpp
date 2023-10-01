#include<bits/stdc++.h>
using namespace std;



int powerofn(int x,int n){
   if(n==0){
      return 1;
   }
   return (x*powerofn(x,n-1));
}

int main(){
   cout<<powerofn(2,3);
}
