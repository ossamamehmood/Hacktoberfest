// https://www.codingninjas.com/codestudio/problems/insertion-sort_3155179



#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j = i - 1;
        while(temp < arr[j] && j >=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}