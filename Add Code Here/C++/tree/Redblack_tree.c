#include<stdio.h>
#include<stdlib.h>

//struct for node of RBT
typedef struct node{
    int data;
    int colour; //0 for black, 1 for red
    struct node* p;    //parent node
    struct node* l;    //left node
    struct node* r;    //right node
}node;

node* root = NULL, *root1 = NULL;


// function to perform BST insertion in RBT
node* Insert(node* it, node* temp)
{
    // If the tree is empty, return a new node
    if (it == NULL)
        return temp;
 
    // Otherwise move down the tree

    //left branch
    if (temp->data < it->data)
    {
        it->l = Insert(it->l, temp);
        it->l->p = it;
    }

    //right branch
    else if (temp->data > it->data)
    {
        it->r = Insert(it->r, temp);
        it->r->p = it;
    }
 
    return it;
}
 
// Function performing right rotation
void Rrotate(node* temp)
{
    node* left = temp->l;
    temp->l = left->r;
    
    if (temp->l)
        temp->l->p = temp;
    left->p = temp->p;
    
    if (!temp->p)
        root = left;
    
    else if (temp == temp->p->l)
        temp->p->l = left;
    
    else
        temp->p->r = left;
    
    left->r = temp;
    temp->p = left;
}
 
// Function performing left rotation 
void Lrotate(node* temp)
{
    node* right = temp->r;
    temp->r = right->l;

    if (temp->r)
        temp->r->p = temp;
    right->p = temp->p;
    
    if (!temp->p)
        root = right;
    
    else if (temp == temp->p->l)
        temp->p->l = right;
    
    else
        temp->p->r = right;
    
    right->l = temp;
    temp->p = right;
}
 
// This function maintains RBT balance
void maintenance(node* root, node* pt)
{
    node* parent = NULL;
    node* Gparent = NULL;
 
    while ((pt != root) && (pt->colour != 0)
           && (pt->p->colour == 1))
    {
        parent = pt->p;
        Gparent = pt->p->p;
 
        //  Case : A Parent of pt is left child of Grand-parent of pt
        if (parent == Gparent->l)
        {
 
            node* Uncle = Gparent->r;
 
            // Case : 1 The uncle of pt is also red Only Recoloring required
            if (Uncle != NULL && Uncle->colour == 1)
            {
                Gparent->colour = 1;
                parent->colour = 0;
                Uncle->colour = 0;
                pt = Gparent;
            }
 
            else {
 
                // Case : 2 pt is right child of its parent Left-rotation required 
                if (pt == parent->r) {
                    Lrotate(parent);
                    pt = parent;
                    parent = pt->p;
                }
 
                // Case : 3 pt is left child of its parent Right-rotation required 
                Rrotate(Gparent);
                int t = parent->colour;
                parent->colour = Gparent->colour;
                Gparent->colour = t;
                pt = parent;
            }
        }
 
        // Case : B Parent of pt is right child of Grand-parent of
           
        else {
            node* Uncle = Gparent->l;
 
            //  Case : 1 The uncle of pt is also red Only Recoloring required
            if ((Uncle != NULL) && (Uncle->colour == 1))
            {
                Gparent->colour = 1;
                parent->colour = 0;
                Uncle->colour = 0;
                pt = Gparent;
            }
            else {
                // Case : 2 pt is left child of its parent Right-rotation required 
                if (pt == parent->l) {
                    Rrotate(parent);
                    pt = parent;
                    parent = pt->p;
                }
 
                // Case : 3 pt is right child of its parent Left-rotation required 
                Lrotate(Gparent);
                int t = parent->colour;
                parent->colour = Gparent->colour;
                Gparent->colour = t;
                pt = parent;
            }
        }
    }
 
    root->colour = 0;
}
 
// Function to print inorder traversal of RBT
void Inorder(node* it)
{
    if (it == NULL)
        return;
        
    Inorder(it->l);
    printf("%d ", it->data);
    Inorder(it->r);
}
 
// driver code
int main()
{
    int n;
    printf("Enter no. of nodes in tree : ");
    scanf("%d",&n);

    int Nodes[n];

    printf("Enter values : a mid value, some values > mid and some values < mid ");
    for(int i=0;i<n;i++)
    {
        printf("\nNode %d : ",i+1);
        scanf("%d",&Nodes[i]);
    }
    
    for (int i = 0; i < n; i++) {
        // allocating memory to the node 
        node* temp = (node*)malloc(sizeof(node));
        
        temp->r = NULL;
        temp->l = NULL;
        temp->p = NULL;
        temp->data = Nodes[i]; //data as i-th value in the array
        temp->colour = 1;  //red color
 
        // insertion
        root = Insert(root, temp);
        root1 = Insert(root1, temp);
 
        // maintaining tree
        maintenance(root, temp);
    }
 
    printf("\nInorder Traversal of Original Tree (Unbalanced)\n");
    Inorder(root1);

    printf("\n\n");

    printf("\nInorder Traversal of Created Tree\n");
    Inorder(root);    
 
    printf("\n\n");

    return 0;
}
