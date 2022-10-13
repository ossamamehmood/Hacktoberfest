/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        Map<Integer, Integer> map = new HashMap<>();
        int inLen = inorder.length;
        int preLen = preorder.length;
        
        for(int i = 0; i < inLen; i++) {
            map.put(inorder[i], i);
        }
        
        TreeNode root = build(preorder, 0, preLen - 1, inorder, 0, inLen - 1, map);
        
        return root;
    }
    
    public TreeNode build(int preorder[], int preStart, int preEnd, int inorder[], int inStart, int inEnd, Map<Integer, Integer> map) {
        if(preStart > preEnd || inStart > inEnd)
            return null;
        
        TreeNode root = new TreeNode(preorder[preStart]);
        int inRoot = map.get(preorder[preStart]);
        int numLeft = inRoot - inStart;
        root.left = build(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, map);
        root.right = build(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, map);
        
        return root;
    }
}