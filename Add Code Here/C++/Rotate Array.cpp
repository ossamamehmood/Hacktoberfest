// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void arrreverse(int arr[], int s, int e)
    {
    while (s < e)
    {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
    }  
    void rotateArr(int arr[], int d, int n){
        if (n!=0) 
        {
            d=d%n;
            arrreverse(arr,0,d-1);
            arrreverse(arr,d,n-1);
            arrreverse(arr,0,n-1);
            
        }
        // code here
    }
};


int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    
	    ob.rotateArr(arr, d,n);
	    
	   
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  
