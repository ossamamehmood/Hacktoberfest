#include <stdio.h>
#include <stdlib.h>

typedef struct treenode //declaration of binary tree
{
    int value;
    struct treenode *left;
    struct treenode *right;
}treenode;
int flag;

treenode *newNode (int value) //creating the binary tree
{
    treenode* result = malloc(sizeof(treenode));
    if (result != NULL)
    {
        result ->left = NULL;
        result ->right = NULL;
        result ->value = value;
    }
    return result;
}

void searchElements (struct treenode* newNode, int val) //the function to search binary tree elements
{
    if (!newNode)
    {
        return;
    }
    searchElements(newNode->left, val);
    if (newNode->value == val)
    {
        printf ("This is Available in the Binary Tree");
        flag = 1;
    }
    searchElements(newNode->right, val);
}

void printPostOrder (struct treenode* result) //the function to print in postoder traversal
{
    if (result == NULL)
        return;

    printPostOrder(result->left); //left subtree reccur
    printPostOrder(result->right); //right subtree reccur     
    
    printf("%d ", result->value); //print the complete node
}

int main()
{

    int s_value;
    
    //insert node values
    struct treenode* root = newNode(8);
    root->left = newNode(6);
    root->right = newNode(10);
    root->left->left = newNode(4);
    root->left->right = newNode(7);
    root->right->right = newNode(12);

    printf("Enter the value to search :- ");
    scanf("%d", &s_value);

    searchElements(root,s_value);

    //check the presence of entered value
    if (flag == 0)
    {
        printf ("!! Element NOT FOUND !!\n");
    }
    
    printf ("\n\nPostorder Traversal is :-\n");
    printPostOrder(root);

    getchar();
    return 0;

}
