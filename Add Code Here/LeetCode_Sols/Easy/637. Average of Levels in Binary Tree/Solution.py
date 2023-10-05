class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        list = []
        q = [root]
        while len(q):
            n = len(q)
            sum = 0
            for i in range(n):
                node = q.pop(0)
                sum += node.val
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            list.append(sum/n)
        return list
