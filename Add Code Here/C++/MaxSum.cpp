//MAximum subarray sum
#include<bits/stdc++.h>
using namespace std;

//Kaden's Algorithm's
/*
Simple idea of the Kadane’s algorithm is to look for all positive contiguous segments of the array (curr_max is used for this).
And keep track of maximum sum contiguous segment among all positive segments (maxVal is used for this).
Each time we get a positive sum compare it with maxVal and update max_so_far if it is greater than maxVal
*/
int main(){
    int n;
    cin>>n;
    long long arr[n];
    for(int i = 0 ;i<n ;i++)
        cin>>arr[i];

    long long maxVal = arr[0];
    long long curr_max = arr[0];

    for(int i = 1 ; i<n ;i++){
        curr_max = max(curr_max+arr[i], arr[i]);
        maxVal = max(maxVal, curr_max); 
    }
    cout<<maxVal;    
    cout<<"\n";
    

}
