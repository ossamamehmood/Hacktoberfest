#include<bits/stdc++.h>
using namespace std;

int findpivot(int a[] , int n ) {

    int s =0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(a[mid] >= a[0]){
            s = mid + 1;
        }else{
            e = mid;
        }

        mid = s + (e-s)/2;

    }
    return s;
    
}
int main(){

    int n;cin>>n;
int a[n];
    for(int i=0;i<n;i++){
cin>>a[i];

    
    }
cout<<findpivot(a , n )<<endl;
return 0;
}
