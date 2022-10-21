// by Sushant Gaurav (@imsushant12)

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *left,*right;
    int height;
};

void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d  ",root->info);
    inorder(root->right);
}

void preorder(struct node* root)
{
   if(root == NULL)
    return;

   printf("%d  ",root->info);
   preorder(root->left);
   preorder(root->right);
}

void postorder(struct node* root)
{
   if(root == NULL)
    return;

   preorder(root->left);
   preorder(root->right);
   printf("%d  ",root->info);
}

int height(struct node *root)
{
    if(root == NULL)
        return 0;
    else
        return root->height;
}

int max(int a,int b)
{
    return (a > b) ? a : b;
}

struct node* LLrotation(struct node *root)
{
    struct node *p1;                         //for adjustments
    struct node *p2;

    p1 = root;                               //A
    p2 = root->left;                         //B

    p1->left = p2->right;                    //A->left = B->right;
    p2->right = p1;                          //B->right = A;

    return p2;                               //new pointer i.e. B
}

struct node* RRrotation(struct node *root)
{
    struct node *p1;                         //for adjustments
    struct node *p2;

    p1 = root;                               //A
    p2 = root->right;                        //B

    p1->right = p2->left;                    //A->right = B->left;
    p2->left = p1;                           //B->left = A;

    return p2;                               //new pointer i.e. B
}

struct node* LRrotation(struct node *root)
{
    struct node *p1;
    struct node *p2;
    struct node *p3;

    p1 = root;                              //A
    p2 = root->left;                        //B
    p3 = root->left->right;                 //C

    p2->right = p3->left;                   //B->right = C->left
    p1->left = p3->right;                   //A->left = C->right
    p3->right = p1;                         //C->right = A
    p3->left = p2;                          //C->left = B

    return p3;                              //C is the new root
}

struct node* RLrotation(struct node *root)
{
    struct node *p1;
    struct node *p2;
    struct node *p3;

    p1 = root;                              //A
    p2 = root->right;                       //B
    p3 = root->right->left;                 //C

    p1->right = p3->left;                   //A->right = C->left
    p2->left = p3->right;                   //B->left = C->right
    p3->right = p2;                         //C->right = B
    p3->left = p1;                          //C->left =

    return p3;                              //C is the new root
}

int nodeheight(struct node* root)
{
    if(root && root->left)
    {
        if(root->left->height > root->right->height)
            return (root->left->height + 1);
    }
    else if(root && root->right)
    {
        if(root->right->height > root->left->height)
            return (root->right->height + 1);
    }
}

int BalanceFactor(struct node* root)
{
    if(root == NULL)
        return 0;
    else
        return(height(root->left) - height(root->right));
}

struct node* create(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

struct node* AVLinsertion(struct node* root , int data)
{
    if(root == NULL)
    {
        root = create(data);
        return root;
    }

    else if(data < root->info)
        root->left = AVLinsertion(root->left , data);

    else
        root->right = AVLinsertion(root->right , data);

    //node's height will be max of (l-height,r-height) + 1
    root->height = (max(height(root->left) , height(root->right))+1);

    //Insertion is done now conditions for rotation if needed.
    if(BalanceFactor(root)==2 && BalanceFactor(root->left)==1)
        return LLrotation(root);

    if(BalanceFactor(root)==2 && BalanceFactor(root->left)==-1)
        return LRrotation(root);

    if(BalanceFactor(root)==-2 && BalanceFactor(root->right)==-1)
        return RRrotation(root);

    if(BalanceFactor(root)==-2 && BalanceFactor(root->right)==1)
        return RLrotation(root);

    return root;
}

struct node* minimumnode(struct node *root)
{
    if(root == NULL)
        return NULL;

    if(root->left == NULL)
        return root;

    else
        minimumnode(root->left);
}

struct node* maximumnode(struct node *root)
{
    if(root == NULL)
        return NULL;

    if(root->right == NULL)
        return root;

    else
        maximumnode(root->right);
}

struct node* deleteelement(struct node *root , int data)
{

    if(root == NULL)
        return root;

    if(data < root->info)
        root->left = deleteelement(root->left , data);

    else if(data > root->info)
        root->right = deleteelement(root->right , data);

    else
    {
        if(root->left != NULL && root->right != NULL)
        {
            struct node* temp = minimumnode(root->right);
            root->info = temp->info;
            root->right = deleteelement(root->right , temp->info);
        }

        else if(root->left != NULL)
            return (root->left);

        else if(root->right != NULL)
            return(root->right);

        else                                                                     //both left and left is null
            return NULL;
    }

    if(root == NULL)
        return root;

    root->height = 1+(max(height(root->left) , height(root->right)));

    if(BalanceFactor(root)==2 && BalanceFactor(root->left)==1)
        return LLrotation(root);

    else if(BalanceFactor(root)==2 && BalanceFactor(root->left)==-1)
        return LRrotation(root);

    else if(BalanceFactor(root)==-2 && BalanceFactor(root->right)==-1)
        return RRrotation(root);

    else if(BalanceFactor(root)==-2 && BalanceFactor(root->right)==1)
        return RLrotation(root);

    return root;
}

int checkAVL(struct node* root)
{
    if(root == NULL)
        return 1;

    int left = checkAVL(root->left);
    int right = checkAVL(root->right);

    if(BalanceFactor(root) >= -1 && BalanceFactor(root) <= 1)
        return 1;

    return 0;
}



int main()
{
    struct node *root = NULL;
    int data,choice;
    while(1)
    {
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Traversal");
        printf("\n4. Check for AVL");
        printf("\n5. EXIT");
        printf("\nENTER CHOICE : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            {
                while(1)
                {
                    printf("\nEnter element or press -1 : ");
                    scanf("%d",&data);
                    if(data == -1)
                        break;
                    else
                        root = AVLinsertion(root , data);
                }
                break;
            }

        case 2:
            {
                printf("\nEnter element to be deleted : ");
                scanf("%d",&data);
                deleteelement(root , data);
                break;
            }

        case 3:
            {
                printf("\nPre-order traversal of the tree formed = ");
                preorder(root);

                printf("\nIn-order traversal of the tree formed = ");
                inorder(root);

                printf("\nPost-order traversal of the tree formed = ");
                postorder(root);

                break;
            }

        case 4:
            {
                if(checkAVL(root) == 1)
                    printf("\nTree is AVL");
                else
                    printf("\nTree is not AVL");
                break;
            }

        case 5:
            {
                exit(0);
                break;
            }

        default:
            printf("\nINVALID CHOICE\n");
        }
    }
    return 0;
}

/*

Sample Input/Output:

1. Insertion
2. Deletion
3. Traversal
4. Check for AVL
5. EXIT
ENTER CHOICE : 1

Enter element or press -1 : 15

Enter element or press -1 : 10

Enter element or press -1 : 20

Enter element or press -1 : -1

1. Insertion
2. Deletion
3. Traversal
4. Check for AVL
5. EXIT
ENTER CHOICE : 3

Pre-order traversal of the tree formed is : 15  10  20
In-order traversal of the tree formed is : 10  15  20
Post-order traversal of the tree formed is : 10  20  15
1. Insertion
2. Deletion
3. Traversal
4. Check for AVL
5. EXIT
ENTER CHOICE : 4

Tree is AVL
1. Insertion
2. Deletion
3. Traversal
4. Check for AVL
5. EXIT
ENTER CHOICE : 2

Enter element to be deleted : 10

1. Insertion
2. Deletion
3. Traversal
4. Check for AVL
5. EXIT
ENTER CHOICE : 3

Pre-order traversal of the tree formed is : 15  20
In-order traversal of the tree formed is : 15  20
Post-order traversal of the tree formed is : 20  15
1. Insertion
2. Deletion
3. Traversal
4. Check for AVL
5. EXIT
ENTER CHOICE : 4

Tree is AVL
1. Insertion
2. Deletion
3. Traversal
4. Check for AVL
5. EXIT
ENTER CHOICE : 5


Time Complexity :
    Insertion - O(logn)
    Deletion - O(logn)
    Traversal- O(n)
    CheckAVL - O(1)
Space Complexity : O(n)

*/
