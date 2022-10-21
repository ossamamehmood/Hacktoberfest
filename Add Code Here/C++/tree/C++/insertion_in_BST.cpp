#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};

Node *insert_bst(Node *head, int data)
{
    Node *node = new Node();
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    if (head->left == head)
    {
        head->left = node;
        return head;
    }
    Node *curr = new Node();
    Node *parent = new Node();
    curr = head->left;
    parent = head;
    while (curr != NULL)
    {
        parent = curr;
        if (data < curr->key)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (data > parent->key)
    {
        parent->right = node;
    }
    else
    {
        parent->left = node;
    }
    return head;
}
void rprintInorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    rprintInorder(node->left);

    /* then print the data of node */
    cout << node->key << " ";

    /* now recur on right child */
    rprintInorder(node->right);
}

Node *delete_bst(Node *head, int data)
{
    if (head->left == head)
    {
        cout << "Empty tree";
        return NULL;
    }
    Node *curr = new Node();
    Node *parent = new Node();
    curr = head->left;
    parent = head;
    char dir = 'l';
    bool found = false;
    while (!found && curr != NULL)
    {
        if (data == curr->key)
        {
            found = true;
            break;
        }
        parent = curr;
        if (data < curr->key)
        {
            curr = curr->left;
            dir = 'l';
        }
        else
        {
            curr = curr->right;
            dir = 'r';
        }
    }
    if (found == false)
    {
        cout << "Node " << data << " is not found in the tree" << endl;
        return NULL;
    }
    Node *node = new Node();
    if (curr->left == NULL)
    {
        node = curr->right;
    }
    else if (curr->right == NULL)
    {
        node = curr->left;
    }
    else
    {
        Node *pred = new Node();
        Node *suc = new Node();
        suc = curr->right;
        if (suc->left == NULL)
        {
            suc->left = curr->left;
            node = suc;
        }
        else
        {
            pred = curr->right;
            suc = pred->left;
            while (suc->left != NULL)
            {
                pred = suc;
                suc = pred->left;
            }
            pred->left = suc->right;
            suc->left = curr->left;
            suc->right = curr->right;
            node = suc;
        }
    }
    if (dir == 'l')
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }
    curr->left = NULL;
    curr->right = NULL;
    delete (curr);
    return head;
}
// Node * rdelete_bst(Node *head,int data){
//     if(head==NULL){
//         // cout<<"Empty tree";
//         return NULL;
//     }
//     Node* curr=new Node();
//     Node* parent=new Node();
//     curr=head;
//     parent=head;
//     char dir='l';
//     bool found=false;
//     while(!found && curr!=NULL){
//        if(data==curr->key){
//            found=true;
//            break;
//        }
//        parent=curr;
//        if(data<curr->key){
//            curr=curr->left;
//            dir='l';
//        }
//        else{
//            curr=curr->right;
//            dir='r';
//        }
//     }
//     if(found==false){
//         cout<<"Node not found"<<endl;
//         return NULL;
//     }
//     if(curr->left==NULL && curr->right==NULL){
//         // cout<<"yes";
//         delete(curr);
//         return head;
//     }
//     Node * node=new Node();
//     Node * pred=new Node();
//         int tmp=curr->key;
//     if(curr->right!=NULL){
//         node=curr->right;
//     while(node->left!=NULL){
//         pred=node;
//         node=node->left;
//     }
//      curr->key=node->key;
//      node->key=tmp;
//     }
//     else{
//         if(curr->left!=NULL){
//             if(dir=='r'){
//                 parent->right=curr->left;
//             }
//             else{
//                 parent->left=curr->left;
//             }
//         }
//         else{
//             if(dir=='l'){
//             parent->left=NULL;
//             }
//             else{
//             parent->right=NULL;
//             }
//         }
//         delete(curr);
//         return head;
//     }
//     rdelete_bst(node,data);
//     return head;
// }
void rprintPreorder(struct Node *node)
{
    if (node == NULL)
        return;

    cout << node->key << " ";

    rprintPreorder(node->left);

    rprintPreorder(node->right);
}
int main()
{
    Node *head = new Node();
    head->left = head;
    head->right = head;
    int n, m;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        head = insert_bst(head, tmp);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        head = delete_bst(head, tmp);
    }
    // head = delete_bst(head, 20);
    rprintInorder(head->left);
    cout << endl;
    rprintPreorder(head->left);
    return 0;
}