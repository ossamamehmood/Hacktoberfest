Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [1,2]
Example 5:


Input: root = [1,null,2]
Output: [1,2]

Solution :
Time Complexity & Space Complexity - O(N) where N is the number of elements in the tree

class Solution {
public:
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return ans;
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        
        return ans;
    }
};

For GFG :

void traverse(Node* root, vector<int>& ans) {
        if(root == NULL) return;

        ans.push_back(root->data);
        traverse(root->left, ans);
        traverse(root->right, ans);
}

vector <int> preorder(Node* root)
{
// Your code here
    vector<int> ans;
    traverse(root, ans);
    return ans;
}
