class Solution {
    List<Integer> order = new ArrayList<Integer>();
    public List<Integer> postorderTraversal(TreeNode root) {
        traverse(root);
        return order;
    }
    
    public void traverse(TreeNode root){
        if(root == null) return;
        traverse(root.left);
        traverse(root.right);
        order.add(root.val);
    }
}
