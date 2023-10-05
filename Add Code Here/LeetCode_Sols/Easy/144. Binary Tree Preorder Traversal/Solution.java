class Solution {
    List<Integer> order = new ArrayList<Integer>();
    public List<Integer> preorderTraversal(TreeNode root) {
        traverse(root);
        return order;
    }
    
    public void traverse(TreeNode root){
        if (root == null) return;
        order.add(root.val);
        traverse(root.left);
        traverse(root.right);
    }
}
