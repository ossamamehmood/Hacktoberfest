//  Using recursion
class Solution {
    int n = 0;
    public int goodNodes(TreeNode root) {
        goodNode(root, root.val);
        return n;
    }
    
    public void goodNode(TreeNode root, int lastMax){
        if(root == null) return;
        if(root.val >= lastMax){
            n++;
            lastMax = root.val;
        }
        goodNode(root.left, lastMax);
        goodNode(root.right, lastMax);
    }
}
