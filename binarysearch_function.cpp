#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int x = 0; x <n; ++x)
    cin>>arr[x];
    int key;
    cin>>key;
    if(binary_search(arr.begin(),arr.end(),key))
    cout<<"Present.";
    else 
    cout<<"Not present.";
}