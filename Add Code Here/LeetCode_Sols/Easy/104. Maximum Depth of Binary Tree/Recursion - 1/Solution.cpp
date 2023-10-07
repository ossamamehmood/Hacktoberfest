class Solution {
public:
    int maxDepth(TreeNode* root) {
        return traverse(root, 0);
    }

    int traverse(TreeNode* node, int depth) {
        if(!node) {
            return depth;
        }
        return max(
            traverse(node->left,depth),
            traverse(node->right,depth)
        ) + 1;
    }
};