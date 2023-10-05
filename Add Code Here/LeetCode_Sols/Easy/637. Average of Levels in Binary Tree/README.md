# Problem #637 ([]() | Binary Tree, Breadth First Search, Depth First Search, Tree)

Given the `root` of a binary tree, return *the average value of the nodes* on each level in the form of an array. Answers within `10`<sup>-5</sup> of the actual answer will be accepted.

## Example 1
![image](https://user-images.githubusercontent.com/89616705/188054900-720e869c-e4ad-446f-86e9-ac251aa1191d.png)

**Input:** 

    root = [3,9,20,null,null,15,7]
<br/>

**Output:**

    [3.00000,14.50000,11.00000]
<br/>

**Explanation:** <br/>

    The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
    Hence return [3, 14.5, 11].

## Example 2
![image](https://user-images.githubusercontent.com/89616705/188056604-9b5c84ee-8230-41ef-9292-3aec863c3977.png)

**Input:**

    root = [3,9,20,15,7]
<br/>

**Output:**

    [3.00000,14.50000,11.00000]

## Constraints
- The number of nodes in the tree is in the range [1, 104].
- -2<sup>31</sup> <= Node.val <= 2<sup>31</sup> - 1

# Solutions

## Breadth First Search

The idea is to create a `Queue` which stores the nodes in each level of the ***Binary Tree***, *by default `root` node is inserted first*. For each node in a level, the average of the sum is stored inside a `List`.
<br/>

**The code is structured as such:**
```cpp
vector<double> list;
```
- create a list which will stores ***double*** values that corresponding the average of the values for each level of the ***Binary Tree***.
<br/>

```cpp
queue<TreeNode*> q;
q.push(root);
```
- Create a ***Queue*** which will store the nodes in a level. Add the `root` *node* to the queue.
<br/>

```cpp
while(!q.empty()){
    // ...statements
}
```
- Execute statements while ***Queue*** is not empty.
<br/>

**Inside the while loop:**
```cpp
while(!q.empty()){
    int n = q.size();
    double sum = 0.0;
}
```
- Create the variables `n` and `sum` which represents the current size of the ***Queue****(The number of nodes in a level)* and the sum of the values in a level.
<br/>

```cpp
while(!q.empty()){
    int n = q.size();
    double sum = 0.0;
    for(int i = 0; i < n; i++){
        TreeNode* node = q.front();
        q.pop();
        sum += q->val;
        if(node->left) q.push(node.left);
        if(node->right) q.push(node.right);
    }
    list.append(sum/n);
}
```
- The *while loop* here iterates through every level of the ***Binary Tree***.
- The *for loop* here gets the value of the nodes in a level and adds it to `sum`. Once the value of the node is added to the sum it is then removed from the ***Queue***.
- The *if statements* here will store the nodes at the next level(*except null*) that will then be used in the next iteration.
- Exiting the *for loop*, the average is of a level is added to the ***List***.
<br/>

***Exiting the while loop...***

```cpp
return list;
```
- return the list which contains the average value of each level of the ***Binary Tree***.

### Code

- **Java**
```java
class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> list = new ArrayList<Double>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while(!q.isEmpty()){
            int n = q.size();
            double sum = 0.0;
            for(int i = 0; i < n; i++){
                TreeNode curr = q.poll();
                sum += curr.val;
                if(curr.left != null) q.add(curr.left);
                if(curr.right != null) q.add(curr.right);
            }
            list.add(sum/n);
        }
        return list;
    }
}
```
<br/>

- **C**++
```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> list;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sum = 0.0;
            for(int i = 0; i < n;  i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            list.push_back(sum/n);
        }
        return list;
    }
};
```
<br/>

- **Python3**
```python3
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
```

### Complexity
- **Time:** `O(n)`
- **Space:** `O(n)`
