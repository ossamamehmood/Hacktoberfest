You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105

---------------------------


class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& e){
        // memset(dp,-1,sizeof(dp));
        
        sort(e.begin(),e.end(),comp);
        vector<int> nums;
        for(auto x:e) nums.push_back(x[1]);
       
       // O(nlogn)
        vector<int> tmp;
        int ans=1;
        tmp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>tmp.back()) tmp.push_back(nums[i]),ans++;
            else{
                int idx=lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin();
                tmp[idx]=nums[i];
            }
        }
        return ans;
    }
};
