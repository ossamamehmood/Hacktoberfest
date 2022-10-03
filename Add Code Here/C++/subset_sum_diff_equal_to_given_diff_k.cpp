#include <bits/stdc++.h>
using namespace std;

int targetsum(int arr[],int n,int sum){
if(n==0){
    return 0;
}
if(sum==0){
    return 1;
}

if(arr[n-1]>sum){
    return targetsum(arr,n-1,sum);
}

return targetsum(arr,n-1,sum) + targetsum(arr,n-1,sum-arr[n-1]);
}

int main (){
    int n,d;
    cin>>n>>d;
    int arr[n];
    int total=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total+=arr[i];
    }

    int sum=(d+total)/2;
    cout<<targetsum(arr,n,sum);

    
}