#include <stdio.h>
#include <stdlib.h>

//node datatype declaration for a binary search tree
typedef struct nod{
    int d;
    struct node * l;
    struct node * r;
}node;

//a function to create a node with a given value and return the pointer to the node 
node* init(int data){
    node* n=malloc(sizeof(node));
    n->d=data;
    n->l=NULL;
    n->r=NULL;
}

//pre order traversal of tree
void printNLR(node * root){
    if(root==NULL)return;
    printf("%d ", root->d);
    printNLR(root->l);
    printNLR(root->r);
}

//in order traversal of tree
void printLNR(node * root){
    if(root==NULL)return;
    printLNR(root->l);
    printf("%d ", root->d);
    printLNR(root->r);
}

//post order traversal of tree
void printLRN(node * root){
    if(root==NULL)return;
    printLRN(root->l);
    printLNR(root->r);
    printf("%d ", root->d);
}

//function which finds the node with a given key value stored in data and returns it pointer
node * seach(node * root, int key){
    if(root->d==key||root==NULL)return root;
    if(key<root->d)return search(root->l, key);
    else return search(root->r, key);
}

//function which inserts a key
node * insert(node * root, int key){
    if(root==NULL)return init(key);
    if(key<root->d)root->l=insert(root->l, key);
    else if(key>root->d) root->r=insert(root->r, key);
    else{
        printf("Key is already present. \n");
    }
    return root;
}

//function to print the tree with the level of each node
void printtree(node *root, int lvl){
    if(root==NULL)return;
    printtree(root->l, lvl+1);
    printf("%d [%d] ", root->d, lvl);
    printtree(root->r, lvl+1);
}

//returns the maximum value stored in tree
int maxkey(node *root){
    while(root->r!=NULL)root=root->r;
    return root->d;
}

//returns the minimum value stored in tree
int minkey(node *root){
    while(root->l!=NULL)root=root->l;
    return root->d;
}

//return the pointer to minimum value containing node
node * minnode(node *root){
    if(root==NULL)return NULL;
    while(root->l!=NULL)root=root->l;
    return root;
}

//returns the pointer to maximum value containing node
node * maxnode(node *root){
    if(root==NULL)return NULL;
    while(root->r!=NULL)root=root->r;
    return root;
}

//function for deleting a node containing a given key value
node * delete(node *root, int key){
    if(root==NULL)return NULL;
    else if(root->d<key)root->l=delete(root->l, key);
    else if(root->d>key)root->r=delete(root->r, key);
    else{
        if(root->l==NULL && root->r==NULL){
            free(root);
            return NULL;
        }
        else if(root->l!=NULL && root->r==NULL){
            node * temp=root->l;
            free(root);
            return temp;
        }
        else if(root->l==NULL && root->r!=NULL){
            node * temp=root->r;
            free(root);
            return temp;
        }
        else{
            node *temp=minnode(root->r);
            root->d=temp->d;
            root->r=delete(root->r, root->d);
        }
    }
    return root;
}


