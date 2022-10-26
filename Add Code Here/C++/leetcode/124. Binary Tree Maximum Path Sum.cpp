/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int maxnodes(TreeNode* root, int &maxm) {
    if (root == nullptr) {
        return 0;
    }

    int lh = maxnodes(root->left, maxm);
    int rh = maxnodes(root->right, maxm);

    maxm = max(maxm, lh + rh + root->val);

    return max(0, root->val + max(lh, rh));

}

class Solution {
public:
    int maxPathSum(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }
        int maxm = root->val;
        maxnodes(root, maxm);
        return maxm;
    }
};