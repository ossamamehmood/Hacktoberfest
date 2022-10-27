#include<iostream>
#include<stdlib.h>
using namespace std;
/*

NOTE: Delete operation issue.

*/
struct node{
    int data;
    struct node *left,*right;
};

struct node *root;

struct node * insert_node(struct node *root,int element){
    if(root == NULL){
        root = new node;
        root->data = element;
        root->left = NULL;
        root->right = NULL;
        return root;
    }else{
        if(root->data > element){
            root->left = insert_node(root->left,element);
        }else{
            root->right = insert_node(root->right,element);
        }
    }
    return root;
}
struct node * find_inorder_successor(struct node *ptr){
    if(ptr == NULL){
        return ptr;
    }else{
        if(ptr->left != NULL){
            find_inorder_successor(ptr->left);
        }else{
            return ptr;
        }
    }
    return ptr;
}
struct node * deletenode(struct node *ptr,int element){
    if(ptr == NULL){
        return ptr;
    }
    
    if(ptr->data == element){
       
        if(ptr->left == NULL and ptr->right == NULL){
            
            return NULL;
        }
        else if(ptr->left == NULL){
            struct node *n = find_inorder_successor(ptr->right);
            
            ptr->data = n->data;
            ptr->right = deletenode(ptr->right,ptr->data);
        }else{
            struct node *n = find_inorder_successor(ptr->left);
            
            ptr->data = n->data;
            ptr->left = deletenode(ptr->left,ptr->data);
        }
    }else if(ptr->data < element){
        ptr->right = deletenode(ptr->right,element);
    }else{
        
        ptr->left = deletenode(ptr->left,element);
    }
    return ptr;
}
void preorder_traversal(struct node *ptr){
    if(ptr == NULL){
        return;
    }
    cout << ptr->data << " ";
    preorder_traversal(ptr->left);
    preorder_traversal(ptr->right);
}

void inorder_traversal(struct node *ptr){
    if(ptr == NULL) return;
    inorder_traversal(ptr->left);
    cout << ptr->data << " ";
    inorder_traversal(ptr->right);
}

void postorder_traversal(struct node *ptr){
    if(ptr == NULL) return;
    postorder_traversal(ptr->left);
    postorder_traversal(ptr->right);
    cout << ptr->data << " ";
}
int main(){
    root = insert_node(root,34);
    root = insert_node(root,33);
    root = insert_node(root,44);
    root = insert_node(root,46);
    preorder_traversal(root);
    root = deletenode(root,46);
    cout << endl;
    preorder_traversal(root);
    cout << endl;
   
    return 0;
}