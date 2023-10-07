# Problem #429 ([N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/) | Tree, Breadth-First Search)
![image](https://user-images.githubusercontent.com/89616705/188376789-0f09f050-d1cd-42bf-9461-6e28c920316e.png)

Given an n-ary tree, return the *level order* traversal of its nodes' values.

*Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).*

## Example 1
![image](https://user-images.githubusercontent.com/89616705/188394865-29b3d863-18af-4c71-8a88-b275708f75f0.png)

**Input:**

    root = [1,null,3,2,4,null,5,6]
<br/>

**Output:**

    [[1],[3,2,4],[5,6]]

## Example 2
![image](https://user-images.githubusercontent.com/89616705/188396638-081590a1-f35f-423b-b0c8-58bbbd9dfd41.png)

**Input:**

    root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<br/>

**Output:**

    [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]

## Constraints
- The height of the n-ary tree is less than or equal to 1000
- The total number of nodes is between [0, 10<sup>4</sup>]

# Solutions

## Breadth-First Search(Iterative) - Queue



### Code
- **Java**
```java
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        if(root == null) return new ArrayList<List<Integer>>();
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        while(!q.isEmpty()){
            List<Integer> level = new ArrayList<Integer>();
            int n = q.size();
            for(int i = 0; i < n; i++){
                Node curr = q.poll(); 
                level.add(curr.val);
                for(Node node: curr.children){
                    q.add(node);
                }
            }
            res.add(level);
        }
        return res;
    }
}
```
![image](https://user-images.githubusercontent.com/89616705/188382963-319ff10a-4c49-4744-bd8a-5af21c2cf2f3.png)
<br/>

- **C++**
```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            for(int i = 0; i < n; i++){
                Node* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                for(Node* node: curr->children){
                    q.push(node);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};
```
![image](https://user-images.githubusercontent.com/89616705/188386462-05581f88-9631-4da8-8dbe-f03734e6f66b.png)
<br/>

- **Python3**
``` python3
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        res = []
        q = [root]
        while len(q):
            level = []
            for i in range (len(q)):
                curr = q.pop(0)
                level.append(curr.val)
                for node in curr.children:
                    q.append(node)
            res.append(level)
        return res;
```
![image](https://user-images.githubusercontent.com/89616705/188390906-1eadee98-9ee8-47b5-b49d-65c4aab49e58.png)

### Complexity
- **Time:** `O(n^2)`, all nodes are traversed twice.
- **Space:** `O(n)`

## Breadth-First Search(Iterative) - HashMap and Queue

### Code

- **Java**
```java
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        if(root == null) return new ArrayList<List<Integer>>();
        Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        int r = 0;
        map.put(r, new ArrayList<Integer>());
        map.get(r++).add(root.val);
        int minNode = 1;
        int maxNode = 1 + root.children.size();
        int nodeCount = maxNode;
        while(!q.isEmpty()){
            Node curr = q.poll();
            int n = curr.children.size();
            if(!map.containsKey(r))
                map.put(r, new ArrayList<Integer>());
            for(Node node: curr.children){
                map.get(r).add(node.val);
                maxNode += node.children.size();
                q.add(node);
                minNode++;
            }
            if(minNode == nodeCount && n != 0){
                nodeCount = maxNode;
                r++;
            }
        }
        List<List<Integer>> lists = new ArrayList<List<Integer>>();
        for(int i = 0; i < r; i++){
            lists.add(map.get(i));
        }
        return lists;
    }
}
```
![image](https://user-images.githubusercontent.com/89616705/188400145-82d862dd-e5aa-4bcd-89a1-20acde86fbaf.png)

### Complexity
- **Time:** `O(n^2)`, all nodes are traversed twice.
- **Space:** `O(n)`
