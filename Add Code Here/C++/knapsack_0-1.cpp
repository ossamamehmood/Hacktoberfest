#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//Recursive Solution
int knapsackRecursive(int wt[],int val[],int w,int n){
    if(w==0||n==0){
        return 0;
    }
    if(wt[n-1]<=w){
        return max(val[n-1]+knapsackRecursive(wt,val,w-wt[n-1],n-1),knapsackRecursive(wt,val,w,n-1));
    }
    else{
        return knapsackRecursive(wt,val,w,n-1);
    }
}

//Memoization Solution
vector<vector<int>>t(102,vector<int>(1002,-1));
int knapsackMemoization(int wt[],int val[],int w,int n){
    if(w==0||n==0){
        return 0;
    }
    if(t[n][w]!=-1){
        return t[n][w];
    }
    if(wt[n-1]<=w){
        return t[n][w]= max(val[n-1]+knapsackMemoization(wt,val,w-wt[n-1],n-1),knapsackMemoization(wt,val,w,n-1));
    }
    else{
        return t[n][w]= knapsackMemoization(wt,val,w,n-1);
    }
}

//Tabulation Solution
int knapsackTabulation(int wt[],int val[],int w,int n){
    int t[n+1][w+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][w];
}
int main(){
    int n;
    cout<<"Enter value of n :";
    cin>>n;
    int wt[n],val[n];
    cout<<"Enter all first weight then value : ";
    for(int i=0;i<n;i++){
        cin>>wt[i];
        cin>>val[i];
    }
    int w;
    cout<<"Enter maximum capacity of knapsack : ";
    cin>>w;
    cout<<"Maximum profit (Using Recursive) :  "<<knapsackRecursive(wt,val,w,n)<<endl;
    cout<<"Maximum profit (Using DP Memoization) :  "<<knapsackMemoization(wt,val,w,n)<<endl;
    cout<<"Maximum profit (Using DP Tabulation) :  "<<knapsackTabulation(wt,val,w,n)<<endl;
    return 0;
}