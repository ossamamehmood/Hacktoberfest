#include <iostream>  
using namespace std; 

struct Node {  
    int data;  
    Node *left;  
    Node *right;  
};  

struct Node* create(int item)  
{  
    struct Node* node = new Node;  
    node->data = item;  
    node->left = node->right = NULL;  
    return node;  
}  

void search(struct Node* &cur, int item, struct Node* &parent)  
{  
    while (cur != NULL && cur->data != item)  
    {  
        parent = cur;  
        if (item < cur->data)  
            cur = cur->left;  
        else  
            cur = cur->right;  
    }  
}

struct Node* findMinimum(struct Node* cur) 
{  
    while(cur->left != NULL) {  
        cur = cur->left;  
    }  
    return cur;  
}  

struct Node* findMaximum(struct Node* cur) 
{  
    while(cur->right != NULL) {  
        cur = cur->right;  
    }  
    return cur;  
}

struct Node* insertion(struct Node* root, int item)  
{  
    if (root == NULL)  
        return create(item); //return new node if tree is empty  
    if (item < root->data)  
        root->left = insertion(root->left, item);  
    else  
        root->right = insertion(root->right, item);  
    return root;  
}  
void deletion(struct Node*& root, int item) //function to delete a struct Node/  
{  
    struct Node* parent = NULL;  
    struct Node* cur = root;  
    search(cur, item, parent); //find the node to be deleted/  
    if (cur == NULL)  
        return;  
    if (cur->left == NULL && cur->right == NULL) //When node has no children/  
    {  
        if (cur != root)  
        {
        if (parent->left == cur)  
                parent->left = NULL;  
            else  
                parent->right = NULL;  
        }  
        else  
            root = NULL;  
        free(cur);       
    }  
    else if (cur->left && cur->right)  
    {  
        struct Node* succ  = findMinimum(cur->right);  
        int val = succ->data;  
        deletion(root, succ->data);  
        cur->data = val;  
    }  
    else  
    {  
        struct Node* child = (cur->left)? cur->left: cur->right;  
        if (cur != root)  
        {  
            if (cur == parent->left)  
                parent->left = child;  
            else  
                parent->right = child;  
        }  
        else  
            root = child;  
        free(cur);  
    }  
}  



  


int count = 0;
struct Node* kthSmallest(struct Node* root, int k)
{
    if (root == NULL)
        return NULL;
 
    struct Node* left = kthSmallest(root->left, k);
 
    if (left != NULL)
        return left;
 
    count++;
    if (count == k)
        return root;

    return kthSmallest(root->right, k);
}

void printKthSmallest(struct Node* root, int k)
{
    struct Node* res = kthSmallest(root, k);
    if (res == NULL)
        cout << "Not found";
    else
        cout << res->data;
}


int main(){
    struct Node* root = NULL;
    int choice,data;
    do{
        cin >> choice;
        switch(choice){
            case 1:
            cin >> data;
            root = insertion(root,data);
            break;
            case 2:
            cin >> data;
            deletion(root,data);
            break;
            case 3:
            cout << (findMinimum(root))->data << endl << (findMaximum(root))->data << endl;
            break;
            case 4:
            cin >> data;
            printKthSmallest(root,data);
            cout << endl;
            break;
        }
    }while(choice != 0);
    return 0;
}