//Code to find the pivot element in rotated sorted array
//Contribution to Hacktoberfest 2022

#include<bits/stdc++.h>
using namespace std;

//function to find the pivot

int pivot(int arr[],int n){

    //using binary search algorithm

    int s=0;
    int e=n-1;
    
    while(s<e){

        int mid=s+(e-s)/2;

        //if element at mid's index in greater than that of 0th index then we update the s to mid+1 as before that pivot cannot be present

        if(arr[mid]>=arr[0]){
            s=mid+1;
        }

        // else we update e as mid so pivot cannot be present after e

        else 
        e=mid;
         
    }
    
    // Unlike binary search here we return arr[s] instead of mid as our pivot is pointed by arr[s]

     return arr[s];
}
int main(){

    //declaring the array

    int arr[]={7,9,3,5,6};

    //finding the size of the array

    int size=sizeof(arr)/sizeof(arr[0]);

    //declaring a variable to store the answer returned by pivot function

    int piv= pivot(arr,size);

    cout<<"Pivot in the array is : "<<piv;
   
    return 0;
}