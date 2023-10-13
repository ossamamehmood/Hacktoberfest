//Knapsack 0-1 Variation problem
#include<iostream>
using namespace std;

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


int main(){
    int n;
    cout<<"Enter number of element in array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter all array element : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cout<<"Enter value of sum : ";
    cin>>sum;
    if(subsetSum(arr,n,sum)){
        cout<<"Is subset sum possible ? Ans : Yes"<<endl;
    }
    else{
        cout<<"Is subset sum possible ? Ans : No"<<endl;
    }
    
    return 0;
}