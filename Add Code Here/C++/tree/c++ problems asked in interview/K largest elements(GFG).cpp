Given an array of N positive integers, print k largest elements from the array. 

Example 1:

Input:
N = 5, k = 2
arr[] = {12,5,787,1,23}
Output: 787 23
Explanation: First largest element in
the array is 787 and the second largest
is 23.
Example 2:

Input:
N = 7, k = 3
arr[] = {1,23,12,9,30,2,50}
Output: 50 30 23
Explanation: Three Largest element in
the array are 50, 30 and 23.
Your Task:
Complete the function kLargest() that takes the array, N and K as input parameters and returns a list of k largest element in descending order. 

Solution :
class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        vector<int>ans;
        sort(arr, arr + n, greater<int>()); //sorting in descending order
        for (int i = 0; i < k; i++)
            ans.push_back(arr[i]);
            
        return ans;
    }
};

1) Sort the elements in descending order in O(n*log(n)) 
2) Print the first k numbers of the sorted array O(k). 
