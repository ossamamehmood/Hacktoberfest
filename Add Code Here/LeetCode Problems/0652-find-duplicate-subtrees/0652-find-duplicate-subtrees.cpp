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
class Solution {
public:
    // Serialize subtrees and check for duplicates using a post-order traversal
    string serializeSubtrees(TreeNode* node, unordered_map<string, int>& subtrees, vector<TreeNode*>& duplicates) {
        if (!node) return "#"; // Null nodes are represented by '#'
        
        string left = serializeSubtrees(node->left, subtrees, duplicates);
        string right = serializeSubtrees(node->right, subtrees, duplicates);
        
        string s = left + "," + right + "," + to_string(node->val); // Serialize the current subtree
        
        if (subtrees[s] == 1) duplicates.push_back(node); // If a duplicate subtree is found, add to the vector
        
        subtrees[s]++;
        return s;
    }
 vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtrees; // Store serialized subtree and its frequency
        vector<TreeNode*> duplicates; // Store duplicate subtrees
        
        serializeSubtrees(root, subtrees, duplicates); // Traverse the tree and serialize subtrees
        
        return duplicates;
    }
    
};
