#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node*left,*right;
}node;

int  search(node* root,int x){
    while(root!=NULL){
        if(root->key==x){
            return 1;
        }
        else if(root->key<x){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return 0;
}

node* insert(node* root, int x) {
    node* temp = (node*)malloc(sizeof(node));
    temp->key = x;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL) {
        return temp;
    }
    node* parent = NULL;
    node* curr = root;
    while (curr != NULL) {
        parent = curr;
        if (curr->key > x) {
            curr = curr->left;
        } else if (curr->key < x) {
            curr = curr->right;
        } else {
            free(temp);
            return root;
        }
    }
    if (parent->key > x) {
        parent->left = temp;
    } else {
        parent->right = temp;
    }
    return root;
}

void findPredecessorSuccessor(node* root, int key, int* pred, int* succ) {
    node* current = root;
    node* predecessor = NULL;
    node* successor = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (current->left != NULL) {
                predecessor = current->left;
                while (predecessor->right != NULL) {
                    predecessor = predecessor->right;
                }
            }
            if (current->right != NULL) {
                successor = current->right;
                while (successor->left != NULL) {
                    successor = successor->left;
                }
            }
            break;
        } else if (current->key < key) {
            predecessor = current;
            current = current->right;
        } else {
            successor = current;
            current = current->left;
        }
    }

    if (predecessor != NULL) {
        *pred = predecessor->key;
    }
    if (successor != NULL) {
        *succ = successor->key;
    }
}

node* getSuccessor(node* curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

node* deleteNode(node* root, int x) {
    if (root == NULL) {
        return root;
    }
    if (x < root->key) {
        root->left = deleteNode(root->left, x);
    }
    
    else if (x > root->key) {
        root->right = deleteNode(root->right, x);
    }
   
    else {
        
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = getSuccessor(root);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


void inorder(node* Root) {
    if (Root) {
        inorder(Root->left);
        printf("%d ", Root->key);
        inorder(Root->right);
    }
}

int main() {
    node* root = NULL;
    int choice, key, pred, succ;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a key\n");
        printf("2. Search a key\n");
        printf("3. Find in-order predecessor and successor of a key\n");
        printf("4. Delete a key\n");
        printf("5. Print in-order traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("Key %d found in the tree.\n", key);
                } else {
                    printf("Key %d not found in the tree.\n", key);
                }
                break;
            case 3:
                printf("Enter the key to find predecessor and successor: ");
                scanf("%d", &key);
                findPredecessorSuccessor(root, key, &pred, &succ);
                printf("Predecessor: %d\n", pred);
                printf("Successor: %d\n", succ);
                break;
            case 4:
                int x;
                printf("Enter value of key which you want to delete : ");
                scanf("%d",&x);
                root=deleteNode(root,x);
                break;
            case 5:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting Program !!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
