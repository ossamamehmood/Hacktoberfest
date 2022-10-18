// Test implementation

#include <unordered_map>
#include <iostream> 
#include <vector>

using std::unordered_map;
using std::vector;


class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> hash;
        auto end= hash.end();
        vector<int> solution(2,0);
        
        for (int i=0;i<nums.size();i++)
        {
            
            auto find =hash.find(target-nums[i]);
            
            if(find==end)
            {   
                 hash.emplace(nums[i],i);   
            }
            else
                
            {
                solution={find->second,i};
                
                return solution;     
            }     
        }
        return solution;
    }
};