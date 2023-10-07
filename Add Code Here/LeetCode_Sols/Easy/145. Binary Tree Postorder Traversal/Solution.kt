/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun postorderTraversal(root: TreeNode?): List<Int> {
        val result = mutableListOf<Int>()
        if (root == null) return result

        result.addAll(postorderTraversal(root.left))
        result.addAll(postorderTraversal(root.right))
        result.add(root.`val`)

        return result
    }
}