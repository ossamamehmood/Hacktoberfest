// Average case is o(NlogN)
// Worst case is O(n^2)
// Choose a pivot element and for us we will choose last element as pivot element
// Recursively sort quicksort on the both the partion 
// It will also have base case where if we will have one  1 or 0 l emements it will return.
// how to partion the array  
// using the pivot element put the elemts which are smaller on the left side and greater than on the right side.
#include<iostream>
#include<vector>
using namespace std;

int partition(vector <int> &a, int s, int e){
int pivot =a[e];
int i =s-1;
for(int j=s;j<e;j++){
if(a[j]<pivot){
  i++;
  swap(a[i],a[j]);
}
}
swap(a[i+1],a[e]);
return i+1;
}



void quicksort(vector <int> &a,int s, int e){
//base case
if(s>=e){
    return;
}
// recursive case
int p = partition(a,s,e);
quicksort(a,s,p-1);
quicksort(a,p+1,e);
}
    int main(){
    vector<int> arr{10,5,2,0,7,6,4};

    int s=0;
    int e =arr.size()-1;
    quicksort(arr,s,e);
    for(int x:arr){
        cout<<x<<",";

    }
}
