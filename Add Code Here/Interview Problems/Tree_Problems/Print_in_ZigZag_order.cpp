/*

           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 

*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* Binary_Tree(int value)
{
    struct Node* Newnode = (struct Node *)malloc(sizeof(struct Node));

    Newnode->data = value;

    // left and right subtree it points to the NULL
    Newnode->left = NULL;
    Newnode->right = NULL;

    return Newnode;
}

vector<int>ZigZag(Node *root)
{
    // crete the ans vector
    vector<int>Result;

    // base condition
    if(root == NULL)
    {
        return Result;
    }

    // maintain flag variable to change the direction
    bool LeftToRight = true; 

    queue<Node *>q;
    q.push(root);

    // traverse the loop until queue is empty
    while(!q.empty())
    {
        int size = q.size();
        vector<int>ans(size);

        // traverse upto size of the current queue
        for(int  i=0; i<size; i++)
        {
            Node *temp = q.front();
            q.pop();

            // decide what kind of insertion should we have to perform
            // Normal insert
            // reverse insert
            int index = LeftToRight ? i : size-i-1;

            ans[index] = temp->data;

            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        // outside of thr loop we have to negate the flag variable
        // once the insertion perform change the direction
        LeftToRight = !LeftToRight;

        for(auto it:ans)
        {
            Result.push_back(it);
        }
        
    }
    return Result;
}

int main()
{
    // root node
    Node *root = Binary_Tree(7); 

    root->left = Binary_Tree(9);
    root->right = Binary_Tree(7);

    root->left->left = Binary_Tree(8);
    root->left->right = Binary_Tree(8);

    root->right->left = Binary_Tree(6); 
    root->left->left->left = Binary_Tree(10);
    root->left->left->right = Binary_Tree(9);

    vector<int>answer = ZigZag(root); 
    for(auto it: ZigZag(root))
    {
        cout<<it<<" ";
    }

    return 0;
}
