#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode{
	int key;
	int nodeCountL;
	int nodeCountR;
	int height;
    struct bstnode *left;
	struct bstnode *right;
} BSTNode;

typedef struct{
    int nodeCount;
	BSTNode *root;
}BST;

BSTNode *create_bstnode(int k){
    BSTNode *n = (BSTNode*) malloc(sizeof(BSTNode));
    n->key = k;
    n->nodeCountL = n->nodeCountR = n->height = 0;
    n->left = n->right = NULL;
    return n;
}

BST *create_bst(){
    BST *bst = (BST*) malloc(sizeof(BST));
    bst->root = NULL;
    bst->nodeCount = 0;
    return bst;
}

int h(BSTNode *rt){
    if(rt == NULL){
        return -1;
    }
    return rt->height;
}

int getBalance(BSTNode *rt){
    if(rt == NULL){
        return 0;
    }
    return h(rt->left)-h(rt->right);
}

int m(int k,int j){
	if(k >= j){
        return k;
    }else{
        return j;
    } 
}

BSTNode *leftRotate(BSTNode *rt){
	BSTNode *r, *rl;
    r = rt->right;
    rl = r->left;
	r->left = rt;
	rt->right = rl;
    if(rl == NULL){
        rt->nodeCountR = 0;
    }else{
        rt->nodeCountR = (rl->nodeCountL)+(rl->nodeCountR)+1;
    }
    if(rt == NULL){
        r->nodeCountL = 0;
    }else{
        r->nodeCountL = (rt->nodeCountL)+(rt->nodeCountR)+1;
    }
	rt->height = m(h(rt->left), h(rt->right))+1;
	r->height = m(h(r->left), h(r->right))+1;
	return r;
}

BSTNode *rightRotate(BSTNode *rt){
	BSTNode *l, *lr;
	l = rt->left;
	lr = l->right;
	l->right = rt;
	rt->left = lr;
    if(lr == NULL){
        rt->nodeCountL = 0;
    }else{
        rt->nodeCountL = (lr->nodeCountL)+(lr->nodeCountR)+1;
    }
    if(rt == NULL){
        l->nodeCountR = 0;
    }else{
        l->nodeCountR = (rt->nodeCountL)+(rt->nodeCountR)+1;
    }
	rt->height = m(h(rt->left), h(rt->right))+1;
	l->height = m(h(l->left), h(l->right))+1;
	return l;
}

BSTNode *inserthelp(BSTNode *rt, int k){
	if(rt == NULL){
        return rt = create_bstnode(k);
	}
    if(rt->key > k){
        rt->left = inserthelp(rt->left, k);
        rt->nodeCountL++;
    }else{
        rt->right = inserthelp(rt->right, k);
        rt->nodeCountR++;
    }
	rt->height = m(h(rt->left), h(rt->right))+1;
	int balance = getBalance(rt);
	if((balance < -1) && (k >= (rt->right->key))){ //If balance is > 1 or < -1, let rt be the closest unbalanced node to the newly inserted leaf
        rt = leftRotate(rt); //L-rotation (key inserted into the right subtree of the right child of rt)
	}else if((balance > 1) && (k < (rt->left->key))){
        rt = rightRotate(rt); //R-rotation (key inserted into the left subtree of the left child of rt)
	}else if((balance > 1) && (k >= (rt->left->key))){
		rt->left = leftRotate(rt->left);
		rt = rightRotate(rt); //LR-rotation (key inserted into the right subtree of the left child of rt)
	}else if((balance < -1) && (k < (rt->right->key))){
		rt->right = rightRotate(rt->right);
		rt = leftRotate(rt); //RL-rotation (key inserted into the left subtree of the right child of rt)
	}
	return rt;
}

void insert(BST *bst, int k){
    bst->root = inserthelp(bst->root, k);
    bst->nodeCount++;
}

int findhelp(BSTNode *rt, int k, int index){
    if(rt == NULL){
        return -1; //Element not found in the AVL
    }
    if(rt->key > k){
        return findhelp(rt->left, k, index);
    }else if(rt->key == k){
        return ((rt->nodeCountL)+(index)+1); //Returns the index of rt element in the AVL
    }else{
        if(rt->left == NULL){
            index += 1;
        }else{
            index += (rt->left->nodeCountL)+(rt->left->nodeCountR)+2;
        }
        return findhelp(rt->right, k, index);
    }
}

int find(BST *bst, int k){
    return findhelp(bst->root, k, 0);
}

int size(BST *bst){
    return bst->nodeCount;
}

void clear(BST *bst){

}

void preorder(BSTNode *rt){
    if(rt != 0){
        printf("%d\n", rt->key);
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode *rt){
    if(rt != 0){
        inorder(rt->left);
        printf("%d\n", rt->key);
        inorder(rt->right);
    }
}

void posorder(BSTNode *rt){
    if(rt != 0){
        posorder(rt->left);
        posorder(rt->right);
        printf("%d\n", rt->key);
    }
}

int main(){

    return 0;
}
