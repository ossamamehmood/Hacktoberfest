#include<bits/stdc++.h>
using namespace std;
void PrintArray(vector<int>& arr, int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<endl;
    }
}

void insertion_sort(vector<int>& arr, int n){
   
           for(int i=1; i < n; i++){
             int j=i-1;
                int  temp =arr[i];
                for( ;j>=0;j--){
                    if(arr[j]>temp){
                         arr[j+1] =arr[j];
                    }
                    else{
                        break;
                    }
                }
                arr[j+1]=temp;
           }
}


int main(){
  vector <int> arr ={10,1,7,6,14,9};
  insertion_sort(arr,6);
  PrintArray(arr,6);
}