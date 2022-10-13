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
    public TreeNode sortedArrayToBST(int[] nums) {
    
    int len = nums.length;
    if ( len == 0 ) { return null; }
    
    // 0 as a placeholder
    TreeNode head = new TreeNode(0); 
    
    Deque<TreeNode> nodeStack       = new LinkedList<TreeNode>() {{ push(head);  }};
    Deque<Integer>  leftIndexStack  = new LinkedList<Integer>()  {{ push(0);     }};
    Deque<Integer>  rightIndexStack = new LinkedList<Integer>()  {{ push(len-1); }};
    
    while ( !nodeStack.isEmpty() ) {
        TreeNode currNode = nodeStack.pop();
        int left  = leftIndexStack.pop();
        int right = rightIndexStack.pop();
        int mid   = left + (right-left)/2; // avoid overflow
        currNode.val = nums[mid];
        if ( left <= mid-1 ) {
            currNode.left = new TreeNode(0);  
            nodeStack.push(currNode.left);
            leftIndexStack.push(left);
            rightIndexStack.push(mid-1);
        }
        if ( mid+1 <= right ) {
            currNode.right = new TreeNode(0);
            nodeStack.push(currNode.right);
            leftIndexStack.push(mid+1);
            rightIndexStack.push(right);
        }
    }
    return head;
}
}