Given an array arr[] of N elements. Find the number of non-empty subsets whose product of elements is less than or equal to a given integer K.

Example 1:

Input:
N = 4
arr[] = {2, 4, 5, 3}
K = 12
Output:
8
Explanation:
All possible subsets whose 
products are less than 12 are:
(2), (4), (5), (3), (2, 4), (2, 5), (2, 3), (4, 3)
Example 2:
Input:
N = 3
arr[] = {9, 8, 3}
K = 2 
Output:
0
Explanation:
There is no subsets with product less
than or equal to 2.


Your Task:  
You don't need to read input or print anything. Your task is to complete the function numOfSubsets() which takes 2 integers N, and K, 
and an array arr of size N as input and returns the number of subsets with product less equal to K.
  
Solution :

class Solution {
  public:
    int numOfSubsets(int arr[], int n, int k) {
        vector<int>vect1, vect2, subset1, subset2;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>k)
                continue;
            if(i<=n/2)
                vect1.push_back(arr[i]);
            else
                vect2.push_back(arr[i]);
        }
        
        for(int i=0;i<(1<<vect1.size()); i++)
        {
            long long int value = 1;
            for(int j=0;j<vect1.size();j++)
            {
                if(i & (1<<j))
                    value*= vect1[j];
            }
            
            if(value<=k)
                subset1.push_back(value);
        }
        
        for(int i=0;i<(1<<vect2.size()); i++)
        {
            long long int value = 1;
            for(int j=0;j<vect2.size();j++)
            {
                if(i & (1<<j))
                    value*= vect2[j];
            }
            
            if(value<=k)
                subset2.push_back(value);
        }
        
        sort(subset2.begin(), subset2.end());
        
        int count =0;
        for(int i=0;i<subset1.size();i++)
            count+= upper_bound(subset2.begin(), subset2.end(),(k/subset1[i])) - subset2.begin();
            count--;
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends

Link for understanding the approach :
1. https://www.geeksforgeeks.org/number-subsets-product-less-k/
2. https://www.youtube.com/watch?v=E3vpe9EKoSI
