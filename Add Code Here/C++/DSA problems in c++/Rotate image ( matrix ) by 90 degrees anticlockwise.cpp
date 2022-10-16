//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int>>& matrix) {
        int k;
        if(matrix.size()%2==0){
            k=matrix.size()/2;
        }
        else{
            k=matrix.size()/2+1;
        }
        int n=matrix.size();
        for(int i=0;i<k;i++){
            for(int z=0;z<3;z++){
                for(int j=i+1;j<n-i-1;j++){
                    if(z==0){
                        swap(matrix[i][j],matrix[j][n-1-i]);
                    }
                    else if(z==1){
                        swap(matrix[i][j],matrix[n-1-i][n-1-j]);
                    }
                    else if(z==2){  
                        swap(matrix[i][j],matrix[n-1-j][i]);
                    }
                }
                if(z==0){
                    swap(matrix[i][i],matrix[i][n-i-1]);
                }
                else if(z==1){
                    swap(matrix[i][i],matrix[n-i-1][n-i-1]);
                }
                else{
                    swap(matrix[i][i],matrix[n-1-i][i]);
                }
            }
        }
    }


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends
