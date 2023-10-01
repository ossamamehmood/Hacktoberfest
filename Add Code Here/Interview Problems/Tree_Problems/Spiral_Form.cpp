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
vector<int>Spiral(Node *root)
{
    vector<int>Result;

    // base condition
    if(root == NULL)
    {
        return Result;
    }

    // flag variable
    bool LeftToRight = false;

    queue<Node *>q;
    // insert the root node of the tree
    q.push(root);

    // traverse the loop 
    while(!q.empty())
    {
        int size = q.size();
        vector<int>ans(size);

        // traverse the loop upto size
        for(int i = 0; i<size; i++)
        {
            Node *temp = q.front();
            q.pop();

            int index = LeftToRight ? i : size - i - 1;
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

        LeftToRight = !LeftToRight;

        for(auto it:ans)
        {
            Result.push_back(it);
        }

    }
    return Result;

}

/*

           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 9 7 6 8 8 10 9  

*/

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

    vector<int>Ans = Spiral(root);

    for(auto it:Spiral(root))
    {
        cout<<it<<" ";
    }
    
    return 0;
}