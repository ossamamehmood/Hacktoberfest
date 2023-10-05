class Solution {
    List<Integer> order = new ArrayList<Integer>();
    public List<Integer> inorderTraversal(TreeNode root) {
        traverse(root);
        return order;
    }
    
    public void traverse(TreeNode root){
        if(root == null) return;
        traverse(root.left);
        order.add(root.val);
        traverse(root.right);
    }
}
