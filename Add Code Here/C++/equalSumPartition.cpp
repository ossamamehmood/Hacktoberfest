//0-1 knapsack problem

#include<iostream>
using namespace std;

//Subset sum function
bool subsetSum(int arr[],int n,int sum){
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=false;
            }
            if(j==0){
                t[i][j]=true;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=((t[i-1][j-arr[i-1]])||(t[i-1][j]));
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

//Equal sum partition function
bool equalSumPartition(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    return subsetSum(arr,n,sum/2);
}

int main(){
    int n;
    cout<<"Enter number of element in array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter all array element : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    if(equalSumPartition(arr,n)){
        cout<<"Is equal sum partition possible ? Ans : Yes"<<endl;
    }
    else{
        cout<<"Is equal sum partition possible ? Ans : No"<<endl;
    }
    
    return 0;
}