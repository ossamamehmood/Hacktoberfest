/*
    Time Complexity : O(N)
    Space Complexity : O(N)
    
    where 'N' is the number of nodes in the tree.
    
*/

#include <unordered_map>

void inorder(BinaryTreeNode<int> *root, unordered_map<int, vector<int>> &m)
{
    if (root)
    {
        inorder(root->left, m);
        if (root->left)
        {
            m[root->data].push_back(root->left->data);
            m[root->left->data].push_back(root->data);
        }
        if (root->right)
        {
            m[root->data].push_back(root->right->data);
            m[root->right->data].push_back(root->data);
        }
        inorder(root->right, m);
    }
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
	// Initialize map to store edges and vertices.
    unordered_map<int, vector<int>> m;
    
    // Store edges by doing inorder traversal.
    inorder(root, m);
    
    // Initialize queue for bfs traversal.
    queue<int> q;
    
    q.push(start);
    
    // Variable to keep count of number of levels from start node.
    int count = 0;
    unordered_map<int, bool> visited;
    visited[start] = true;
    
    // Iterate while queue is not empty.
    while (!q.empty())
    {
        count++;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int node = q.front();
            q.pop();
            
            for(auto i:m[node])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    
    return count - 1;
}
