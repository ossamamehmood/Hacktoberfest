// Question: Majority Element
// Description: Given an array of size n, majority element is an element that occours more
//  than n/2 times in the array
//  e.g. [1,5,2,5,5] --> Majority element is 5
// Assume that majority element always exists


//Solved using Moore's Voting Algorithm

#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int candidate = arr[0], count = 1;
    for (int i = 1; i < n;i++){
        if(arr[i]==candidate){
            count++;
        }else{
            count--;
        }
        if(count==0){
            candidate = arr[i];
            count = 1;
        }
    }
    cout << candidate << endl;
    return 0;
}