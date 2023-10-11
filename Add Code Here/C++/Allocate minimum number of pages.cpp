#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    bool issafe(int A[],int N,int M,int pages){
        int count=0,sum=0;
        for(int i=0;i<N;i++){
            
            if(sum+A[i] > pages){
                count++;
                sum = A[i];
                if(sum > pages) return false;
            }else{
                sum +=A[i];
            }
        }
        if(count < M) return true;
        return false;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int low = A[0],high=0;
        for(int i=0;i<N;i++){
            low = min(low,A[i]);
            high+=A[i];
        }
        
        int mid;
        while(low<=high){
            
            mid = (low+high)/2;
            if(issafe(A,N,M,mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }
        return low;
        
    }
};


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

