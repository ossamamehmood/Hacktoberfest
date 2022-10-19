Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
  
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
  
Solution :

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int level = 1 , max_level = 0 , max_sum = INT_MIN;
        
        if(root==nullptr)
            return 0;
        
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            int sum = 0;
            
            while(len--){
                TreeNode* front = q.front();
                q.pop();
                
                if(front->right)
                    q.push(front->right);
                if(front->left)
                    q.push(front->left);
                sum = sum + front->val;
            }
            if(sum>max_sum)
            {
                max_sum = sum;
                max_level = level;
            }
            level++;
        }
        return max_level;
    }
};
