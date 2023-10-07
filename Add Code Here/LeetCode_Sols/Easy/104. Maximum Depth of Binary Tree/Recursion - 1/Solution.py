class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.traverse(root, 0)

    def traverse(self, node: Optional[TreeNode], depth) -> int:
        return depth if not node else max(self.traverse(node.left, depth), self.traverse(node.right, depth)) + 1