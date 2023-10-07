# Problem #1448 ([Count Good Nodes in Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/) | Binary Tree, Breadth-First Search, Depth-First Search, Tree)

## Problem

Given a binary tree `root`, a *node X* in the tree is named **good** if in the path from *root to X* there are no nodes with a value *greater than X*.

*Return the number of ***good*** nodes in the binary tree.*

<br/>

## Example 1
![image](https://user-images.githubusercontent.com/89616705/187807013-d9e1c227-23c2-48f3-9e81-8c6472aed25b.png)

**Input:**

    root = [3,1,4,3,null,1,5]
<br/>

**Output:**

    4
<br/>

**Explanation:** `Nodes in blue are good.`

    Root Node (3) is always a good node.
    Node 4 -> (3,4) is the maximum value in the path starting from the root.
    Node 5 -> (3,4,5) is the maximum value in the path
    Node 3 -> (3,1,3) is the maximum value in the path.
<br/>

## Example 2
![image](https://user-images.githubusercontent.com/89616705/187807346-dbc135c9-ccfe-41b2-9dc9-a4a76b363eb3.png)

**Input:**

    root = [3,3,null,4,2]
<br/>

**Output:**

    3
<br/>

**Explanation:**

    Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
<br/>

## Example 3

**Input:**

    root = [1]
<br/>

**Output:*

    1
<br/>

**Explanation:**

    Root is considered as good.
<br/>

# Solutions

## Recursion

The idea is to declare a *global variable(`n`)* to represent the number of **good** nodes. A node is a **good** node if:

    - the path from the root node to node X does not contain a node with value greater than that of node X.
<br/>

To check whether a node is a **good** node, create a *recursive method* with arguments *(TreeNode `root`, int `lastMax`)*. `root` represents the current node while `lastMax` represents the node with the greates value in the current path.

**Method is structured as such:**
```cpp
void goodNode(TreeNode root, int lastMax){}
```
- the method should take a *TreeNode `root`* which refers to the current node and *int `lastMax`* which refers to the greatest value of the path.
<br/>

```cpp
if(root == null) return;
```
- return if at the end of Tree path.
<br/>

```cpp
if(root.val >= lastMax){
    n++;
    lastMax = root.val;
}
```
- if the value of the current node is greater than or equal to `lastMax` then the current node is a **good** node, thus increment `n` and change the value of `lastMax` to the value of the current node.
<br/>

```cpp
goodNode(TreeNode root.left, lastMax);
goodNode(TreeNode root.right, lastMax);
```
- check whether the left and right nodes are **good** nodes.
<br/>

### Code

- **JAVA**
```java
class Solution {
    int n = 0;
    public int goodNodes(TreeNode root) {
        goodNode(root, root.val);
        return n;
    }
    
    public void goodNode(TreeNode root, int lastMax){
        if(root == null) return;
        if(root.val >= lastMax){
            n++;
            lastMax = root.val;
        }
        goodNode(root.left, lastMax);
        goodNode(root.right, lastMax);
    }
}
```

### Complexity
- **Time:** `O(n)`
- **Space:** `O(height)`
