#include <bits/stdc++.h>
using namespace std;

class treeNode
{
  public:
  int data;
  treeNode* left = NULL;
  treeNode* right = NULL;
  treeNode( int data)
  {
      this->data = data;
  }

  ~treeNode()
  {
      delete left;
      delete right;
  }
};

treeNode* takeinput()
{
    int rootdata;
    cout<<"enter root data: ";
    cin>>rootdata;

    if(rootdata == 0)
    {
        return NULL;
    }
    treeNode* root = new treeNode(rootdata);

    queue<treeNode*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        treeNode* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter left child of "<<front->data<<": ";
        int lchild;
        cin>>lchild;
        if(lchild != 0)
        {
            treeNode* child = new treeNode(lchild);
            front->left = child;
             pendingNodes.push(child);
        }

        cout<<"enter right child of "<<front->data<<": ";
        int rchild;
        cin>>rchild;
        if(rchild != 0)
        {
             treeNode* chil = new treeNode(rchild);
            front->right = chil;
            pendingNodes.push(chil);
        }
    }
    return root;
}
void printTree(treeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<": ";
    if(root->left != NULL)
    {
        cout<<"L"<<root->left->data;
    }
    if(root->right != NULL)
    {
        cout<<" R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
void inorder(treeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data <<" ";
    inorder(root->right);
}
void preorder(treeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    
    cout<<root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(treeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    
   
    postorder(root->left);
    postorder(root->right);
     cout<<root->data <<" ";
}

int main()
{
      treeNode* root = takeinput();
   printTree(root);
   cout<<"Preorder traversal is: ";
   preorder(root);
   cout<<endl;
   cout<<"Posteorder traversal is: ";
   postorder(root);
    cout<<endl;
   cout<<"Intorder traversal is: ";
   inorder(root);
   delete(root);
    return 0;
}