# Problem #94 ([Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | Binary Tree, Depth-First Search, Stack, Tree)

Given the `root` of a binary tree, return the *inorder traversal of its nodes' values*.

## Example 1
![image](https://user-images.githubusercontent.com/89616705/189007970-90d48121-5c89-4b5d-aa67-e91b1877afee.png)

### Input:

    root = [1,null,2,3]

### Output:

    [1,3,2]

## Example 2

### Input:

    root = []

### Output:

    []

## Example 3

### Input:

    root = [1]

### Output:

    [1]

## Constraints
- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

***

### Follow up: `Recursive solution is trivial, could you do it iteratively?`

# Solutions

## Stack(Iterative)

### Code

- **Java**
```java
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        List<Integer> list = new ArrayList<Integer>();
        TreeNode curr = root;
        while(curr != null | !stack.isEmpty()){
            while(curr != null){
                stack.add(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            list.add(curr.val);
            curr = curr.right;
        }
        return list;
    }
}
```
![image](https://user-images.githubusercontent.com/89616705/189010656-39103022-6da8-4711-922d-11cae7fa52b2.png)

- **C++**
```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> list;
        TreeNode* curr = root;
        while(curr != NULL || !stack.empty()){
            while(curr != NULL){
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            list.push_back(curr->val);
            curr = curr->right;
        }
        return list;
    }
};
```
![image](https://user-images.githubusercontent.com/89616705/189011321-319cdcb7-febb-4352-8ed1-c9d27b603797.png)

- **Python**
```python
class Solution(object):
    def inorderTraversal(self, root):
        list = []
        stack = []
        curr = root
        while curr or len(stack):
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            list.append(curr.val)
            curr = curr.right
        return list
```
![image](https://user-images.githubusercontent.com/89616705/189012384-bb613e6a-f008-4009-bf7a-cb6601312a41.png)

### Complexity
- **Time:** `O(n)`
- **Space:** `O(n)`


![image](https://user-images.githubusercontent.com/89616705/189011321-319cdcb7-febb-4352-8ed1-c9d27b603797.png)

- **Ruby**
```rb
class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val = 0, left = nil, right = nil)
        @val = val
        @left = left
        @right = right
    end
end

def inorder_traversal(root)
    result = []
    stack = []
    current = root
    while current || stack.length > 0
        while current
            stack.push(current)
            current = current.left
        end
        current = stack.pop()
        result << current.val
        current = current.right
    end
    result
end
```
