class Solution {
    public int maxDepth(TreeNode root) {
        return traverse(root, 0);
    }

    public int traverse(TreeNode node, int depth) {
        if(node == null) {
            return depth;
        }
        return Math.max(
            traverse(node.left, depth),
            traverse(node.right, depth)
        ) + 1;
    }
}