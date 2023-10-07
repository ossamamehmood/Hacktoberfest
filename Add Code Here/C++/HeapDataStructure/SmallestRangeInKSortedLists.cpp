//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range



class Solution{
    public:
    
    class Node{
    public:
    int data;
    int row;
    int col;
    
    Node(int x,int r,int c) {
        data = x;
        row = r;
        col = c;
    }
};
    
class compare{
    public:
    bool operator()(Node *a,Node *b) {
            return a->data > b->data; 
        }
    };
    
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
          //code here
          int mini = INT_MAX;
          int maxi= INT_MIN;
          
          priority_queue<Node *,vector<Node *>,compare> pq;
          
          //find the range for the first k elements
          for(int i = 0;i<k;i++) {
              int ele = a[i][0];
              pq.push(new Node(ele,i,0));
              mini = min(mini,ele);
              maxi = max(maxi,ele);
          }
          
          int start = mini;
          int end = maxi;
          
          while(pq.size()>0) {
              //find next mini
              Node *temp = pq.top();
              int mini = temp->data;
              pq.pop();
              //update answer
              if((end-start) > (maxi-mini)) {
                  end = maxi;
                  start = mini;
              }
              ///find next maxi
              if(temp->col + 1 < n) {
                  maxi = max(maxi,a[temp->row][temp->col+1]);
                  pq.push
                  (new Node(a[temp->row][temp->col+1],temp->row,temp->col+1));
              }
              else {
                  break;
              }
          }
          return {start,end};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends