//Constructing a binary tree using structure and implementing various operations
//OPERATIONS: preorder, postorder, inorder traversal by creating structures

#include<iostream>
#include<iomanip>
using namespace std;

struct binaryTree{
    int val;
    struct binaryTree* l;  //left branch
    struct binaryTree* r;  //right branch
};

struct binaryTree* createtree(int value){
    struct binaryTree* n= new struct binaryTree[1];
    n->l=NULL;
    n->r=NULL;
    n->val= value;
    return n;
}

void preorder(struct binaryTree* n){   // root -> left -> right
    if(n!=NULL){
        cout<<n->val<<" ";  //printing root element
        preorder(n->l);   //moving to left branch
        preorder(n->r);   //moving to right after transversing left branch
    }
}

void postorder(struct binaryTree* n){   // left -> right -> root
    if(n!=NULL){
        postorder(n->l);    //moving to left branch
        postorder(n->r);    //moving to right after transversing left branch
        cout<<n->val<<" "; //printing root element
    }
}

void inorder(struct binaryTree* n){   // left -> root -> right
    if(n!=NULL){
        inorder(n->l);     //moving to left branch
        cout<<n->val<<" ";  //printing root element
        inorder(n->r);     //moving to right after transversing left branch and root branch
    }
}

int main(){
    
    //EXAMPLE
    //constructing a binaryTree structure using createtree function

    struct binaryTree* p = createtree(4);
    struct binaryTree* p1 = createtree(2);
    struct binaryTree* p2 = createtree(8);
    struct binaryTree* p3 = createtree(5);
    struct binaryTree* p4 = createtree(6);   //creating the branches of binary tree

// BINARY TREE LOOKS LIKE: 

//             4
//            / \
//           2   8
//          / \  
//         5   6 
              
    p->l = p1;   //linking the branches of binary tree
    p->r = p2;
    p1->l = p3;
    p1->r = p4;

    cout<<"PreOrder Traversal: ";
    preorder(p);  //preorder traversal
    cout<<endl;
    cout<<"PostOrder Traversal: ";
    postorder(p);  //postorder traversal
    cout<<endl;
    cout<<"InOrder Traversal: ";
    inorder(p);  //inorder traversal
 
    return 0;
}