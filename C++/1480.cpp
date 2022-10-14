class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
// Method - 1 Using Auxiliary Space - O(N) and Time Complexity - O(N).  
//         vector < int > ans ;
//         vector < int >:: iterator it = nums.begin() ;
//         int sum = 0 ;
//         for(int value : nums )
//         {
//             sum = sum + value ;
//             ans.push_back(sum) ;
//         }
        
//         return ans ;
        
        
// Method - 2 - InPlace Solve - O(1) - Space Complexity - Prefix Sum - Array  
    
        for(int i = 1 ; i < nums.size() ; i++)
        {
            nums[i] += nums[i - 1] ; 
        }
        return nums ;
        
    }
};
