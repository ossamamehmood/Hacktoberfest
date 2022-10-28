// https://leetcode.com/problems/binary-tree-right-side-view/

/**
 * LOGIC: Basic recursion with max Depth count
 * - Make sure to recurse right first and then left :)
 * 
 */ 
class Solution {
public:
    void helper(TreeNode* root, int depth, int& depthMaxTill, vector<int>& depthList) {
        if(!root) return;
        if(depth>depthMaxTill) {
            depthList.push_back(root->val);
            depthMaxTill = depth;
        }
        helper(root->right, depth+1, depthMaxTill, depthList);
        helper(root->left, depth+1, depthMaxTill, depthList);
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> depthList = {root->val};
        int maxDepth=0;
        helper(root, 0, maxDepth, depthList);
        return depthList;
    }
};
