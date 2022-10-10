// https://leetcode.com/problems/longest-univalue-path/discuss/108155/C%2B%2B-DFS-with-explanation

// Explanation:-

// Perform DFS by recursively invoking go for left and right subtrees. When coming back up the recursive stack, check to see if the root value is equal to the left and right subtree root value, if so, add one onto the max path value returned by the subtree to include the one additional path between the root and the subtree root.
//
// There are 3 possible use cases to consider when coming back up the recursive stack:
//
// Case 1: If the root value is equal to BOTH the left and right subtree root values, then set m to the maximum of itself compared to the "up-side-down-V shaped" path created by including the left and right subtrees max paths with the root ( l=l+1 and r=r+1 ). Return the max path value of the left and right subtrees return max(l,r) which is needed in case the next parent up the recursive stack is also the same value.
//
// Case 2: If the root value is NOT equal to EITHER the left INCLUSIVE-OR right subtree values, then set BOTH l=0 and r=0 and return 0 ( i.e. return max(0,0) ).
//
// Case 3: If the root value is equal to the left subtree root value XOR the right subtree root value, then either l=0 and r=r+1 XOR l=l+1 and r=0, return the maximum of the left and right subtree path values ( i.e. return max(l,0) XOR return max(0,r) ).
//
// Always check for a new max for each of these 3 use cases by adding the path value of the left subtree and right subtree. m=max(m,l+r). It is OK to add l and r together when checking for a new max for each of the 3 use cases above, since l and/or r are set to 0 when applicable ( i.e. for case 2: 0+0==0 and for case 3: l+0==l XOR 0+r==r ).

// Code:-
struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int longestPath=0;
        go(root, longestPath);
        return longestPath;
    }
private:
    int go(TreeNode* root, int& m){
        int l=root->left ? go(root->left, m) : 0;
        int r=root->right ? go(root->right, m) : 0;
        l=(root->left && root->left->val==root->val) ? l+1 : 0;
        r=(root->right && root->right->val==root->val) ? r+1 : 0;
        m=max(m,l+r);
        return max(l,r);
    }
};
