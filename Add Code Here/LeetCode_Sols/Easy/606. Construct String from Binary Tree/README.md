# Problem #606 ([Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/) | Binary Tree, Depth-First Search, String, Tree)

Given the `root` of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

## Example 1:
![image](https://user-images.githubusercontent.com/89616705/188799689-fcafcbca-2df7-49f1-8180-ea19bc33a455.png)
### Input:

    root = [1,2,3,4]

### Output:

    "1(2(4))(3)"

### Explanation:

    Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary
    empty parenthesis pairs. And it will be "1(2(4))(3)"

## Example 2:
![image](https://user-images.githubusercontent.com/89616705/188799923-1c6379b1-cd03-4cac-8f93-4199969dd510.png)

### Input:

    root = [1,2,3,null,4]

### Output:

    "1(2()(4))(3)"

### Explanation:

    Almost the same as the first example, except we cannot omit the first parenthesis pair
    to break the one-to-one mapping relationship between the input and the output.

## Constraints:
- The number of nodes in the tree is in the range `[1, 104]`.
- `-1000 <= Node.val <= 1000`

# Solutions

## Breadth-First Search(Recursive)

### Code

- **Java**
```java
class Solution {
    public String tree2str(TreeNode root) {
        if(root == null) return "";
        String s = String.valueOf(root.val);
        String left = tree2str(root.left);
        String right = tree2str(root.right);
        if(left == "" && right == "") return s;
        if(right == "") return s + "(" + left + ")";
        if(left == "") return s + "()" + "(" + right + ")";
        return s + "(" + left + ")" + "(" + right + ")";
    }
}
```
![image](https://user-images.githubusercontent.com/89616705/188801332-28829bae-e3f3-42e3-8d90-aac2696abad3.png)

### Complexity
- **Time** `O(log n)`
- **Space** `O(1)`
