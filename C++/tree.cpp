#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

};
int search(int inorder[], int start, int end, int curr)
{
    for(int i = start; i<=end; i++)
    {
        if(inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if(start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    Node* node = new Node();
    node->data=curr;
    if(start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder,inorder,start,pos-1);
    node->right = buildTree(preorder,inorder,pos+1,end);
    return node;
}

void inorderprint(Node* root)
{
    Node* temp = root;
    if(temp == NULL)
    {
        return;
    }
    inorderprint(temp->left);
    cout<<temp->data<<" ";
    inorderprint(temp->right);
}

int main()
{
    // int n;
    // cin>>n;
    int preorder[] = {1,2,4,3,5};
    // for(int i=0; i<n; i++)
    // {
    //     cin>>preorder[i];
    // }
    int inorder[] = {4,2,1,5,3};
    // for(int i=0; i<n; i++)
    // {
    //     cin>>inorder[i];
    // }

    Node* root = buildTree(preorder,inorder,0,4);
    inorderprint(root);

}

