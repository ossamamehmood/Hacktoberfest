#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int x;
    cin>>x;
   int a[n][m];

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
        cin>>a[i][j];
    }

   int r=0,c=m-1;
  
   bool check =false;

while(r<n and c>=0){ 
    
    if(a[r][c]==x){
       check =true;
    }

    if(x>a[r][c]){
        r++;
    }
    else {
        c--;
    }
    
     
}
if(check){
    cout<<"Found ";
}else
cout<<"not found";

   
}