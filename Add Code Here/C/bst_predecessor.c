#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int key;
    struct node *left, *right;
};
 
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* findMaximum(struct node* root)
{
    while (root->right) {
        root = root->right;
    }
 
    return root;
}
struct node* findPredecessor(struct node *root, struct node *prec, int find)
    {
        
        if (root == NULL) {
            return prec;
        }
 
        if (root->key == find)
        {
            if (root->left != NULL) {
                return findMaximum(root->left);
            }
        }
 
       
        else if (find < root->key) {
            return findPredecessor(root->left, prec, find);
        }
 
        
        else {
            prec = root;
            return findPredecessor(root->right, prec, find);
        }
        return prec;
    }
int count =0;


struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    return node;
}
 
int main()
{
    
    struct node* root = NULL;
    int arr[11];
    for(int i = 0 ;i<11;i++)
    {
        scanf("%d",&arr[i]);
    }
    root = insert(root, arr[0]);
    for(int i = 1; i<11;i++)
    {
        insert(root,arr[i]);
    }
    
    int find;
    scanf("%d",&find);
    struct node* prec = findPredecessor(root, NULL, find);
 
        if (prec != NULL) {
            printf("The predecessor for the node %d is %d",find,prec->key);
        }
    
    return 0;
}
