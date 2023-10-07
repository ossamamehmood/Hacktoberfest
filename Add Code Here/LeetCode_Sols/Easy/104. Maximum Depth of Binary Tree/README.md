# Problem #104 ([Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | Binary Tree, Breadth-First Search, Depth-First Search, Tree)

Given the `root` of a binary tree, return its _maximum `depth`_.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

### Example 1

![image](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

**Input:** `root = [3,9,20,null,null,15,7]`

**Output:** `3`

### Example 2

**Input:** `root = [1,null,2]`
**Output:** `2`

### Constraints

- The number of nodes in the tree is in the range [$0$, $10^4$].
- `-100 <= Node.val <= 100`

---

# Solutions

## Approach: Recursion

### Code

- **Java**

```java
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
```

- **C++**

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return traverse(root, 0);
    }

    int traverse(TreeNode* node, int depth) {
        if(!node) {
            return depth;
        }
        return max(
            traverse(node->left,depth),
            traverse(node->right,depth)
        ) + 1;
    }
};
```

- **Python**

```python
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.traverse(root, 0)

    def traverse(self, node: Optional[TreeNode], depth) -> int:
        return depth if not node else max(self.traverse(node.left, depth), self.traverse(node.right, depth)) + 1
```

<!-- ### Complexity

- **Time:** `O(n log n)`
- **Space:** `O(n)` -->
