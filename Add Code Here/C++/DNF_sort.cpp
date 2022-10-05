#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // 3 pointer approach
    // use if-else or switch case

    int low=0, mid=0, high=n-1;

    while(mid <= high){
        switch (arr[mid]){
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    int testcase=1;
    // cin>>testcase;
    while(testcase--){
        solve();
    }
    return 0;
}