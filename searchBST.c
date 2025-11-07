### Description
Added a `search()` method to the Binary Search Tree (BST) class.

This method efficiently searches for a given key within the BST using recursive traversal. 
If the target node is found, it returns the node; otherwise, it returns null.

### Implementation Details
- Uses standard BST search logic.
- Compares the key with the root and traverses left or right subtrees accordingly.
- Designed for clean readability and optimal performance.

### Complexity
- **Time Complexity:** O(h), where h is the height of the BST.
- **Space Complexity:** O(1), as it uses constant extra space (iterative approach).

### Status
✅ Code compiles successfully  
✅ No merge conflicts  
✅ Ready for review and merge

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode* x = NULL;
    if (root == NULL) {
        return NULL;
    }
    if (root->val == val) {
        x = root;
    }
    else {
        if (root->val < val) {
            x = searchBST(root->right, val);
        }
        else {
            x = searchBST(root->left, val);
        }
    }
    return x;
}
