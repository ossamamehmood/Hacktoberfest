class Solution {
    TreeNode node = null;
    public TreeNode searchBST(TreeNode root, int val) {
        traverse(root, val);
        return node;
    }
    
    public void traverse(TreeNode root, int val){
        if(root == null) return;
        if(root.val == val) node = root;
        traverse(root.left, val);
        traverse(root.right, val);
    }
}
