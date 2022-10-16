Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

Solution :
Time Complexity - O(n) where n is the number of nodes in the binary tree
Space Complexity - O(n) because we are using a vector to store the traversal level wise

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans; //incase the root has no value
        
        queue<TreeNode*>q; // queue ds 
        q.push(root);      // pushing the initial root value into the queue
        while(!q.empty())  //if queue is not empty 
        {
            int size = q.size(); // find the size of the queue , which means it gives the size of no. of elements in the queue
            vector<int>level;    // a vector to store level wise traversals 
            for(int i=0;i<size;i++)
            { 
                TreeNode* node = q.front();  //pointer to the front element of the queue 
                q.pop();                      //pop the front element 
                if(node->left!=NULL)          // if node is not null, push the values in the queue 
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                level.push_back(node->val);   // pushing the values of the node in the level vector 
            }
            ans.push_back(level);          // pushing the level vector traversal in the ans vector 
        }
        return ans;                           // returning the answer 
    }
};
