/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun preorderTraversal(root: TreeNode?): List<Int> {
        val result = mutableListOf<Int>()
        helper(root, result)
        return result
    }
    
    fun helper(node: TreeNode?, result: MutableList<Int>) {
        if (node == null) return
        result.add(node.`val`)
        helper(node.left, result)
        helper(node.right, result)
    }
}