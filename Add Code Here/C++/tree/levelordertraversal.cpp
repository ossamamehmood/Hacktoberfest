#include<iostream>
#include<queue>
using namespace std;



class node{
    public:
    int data;
    node *left;
    node *right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

node* buildTree(node* root){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    root=new node(d);
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}



// level order traversal using queue

void levelOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp= q.front();
        q.pop();

        if(temp==NULL){  //if temp is NULL then we have reached the end of current level
            cout<<endl;
            if(!q.empty()){   //if queue is not empty then we have more levels to traverse
                q.push(NULL);
            }
        }
        else{
        // cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        cout<<temp->data<<" ";
        }
    }

}


// preorder postorder inorder traversal
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//  build from level order traversal

void buildFromLevelOrder(node* &root){

    if(root==NULL){
        return ;
    }
    queue<node*>q;

    int data;
    cin>>data;
    root= new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp= q.front();
        q.pop();

        cout<<root->data;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left= new node(leftData);
            q.push(temp->left);
        }

        cout<<root->data;

        int rightData;
        cin>>rightData;
        
        if(rightData!=-1){
            temp->right= new node(rightData);
            q.push(temp->right);
        }
}

 int maxDepth(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        int depth= 0;
        
        queue<TreeNode*> q;
        q.push(root);
        // q.push(NULL);
        
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            
            if(frontNode->left==NULL && frontNode->right==NULL){
             depth++;   
            }
            
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
              
        }
        return depth;
    }

int main(){
    node* root=NULL;
    root=buildTree(root);      //creating the tree
    // levelOrderTraversal(root);
    return 0;
}