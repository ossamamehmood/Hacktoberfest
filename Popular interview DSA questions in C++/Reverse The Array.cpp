// https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298?leftPanelTab=0


#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
    int j = arr.size();
    for(int i = 0; i<j;i++){
        if(i>m){
            swap(arr[i],arr[j-1]);
            j--;
        }
    }
}
