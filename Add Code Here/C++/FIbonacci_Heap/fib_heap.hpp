#ifndef HEAP_HPP_INCLUDED
#define HEAP_HPP_INCLUDED

#include<cstdbool>

typedef struct node{

    int key;
    int degree;
    bool mark;
    struct node *left;
    struct node *right;
    struct node *parent;
    struct node *child;

}node;

typedef struct heap{
    int n;
    node *min;
    int degree;
    int potential;
}heap;

void initHeap(heap *h);
node* initNode(int val);
void insert(heap *h, int val);
heap* unionOfHeaps(heap *h1, heap *h2);
void merge(heap *h, node *n1, node *n2);
int calculateDegree(int n);
void consolidate(heap *h);
void printHeap(heap h);
node* extractMin(heap *h);
void cut(heap *h, node *target);
void cascadingCut(heap *h, node *parent);
void decreaseKey(heap *h, node *target, int val);
node* findNode(node* h, int key);
int totalMarkedNodes(node* h);
int totalrootNodes(node* h);
void meld(heap *h, node* target);
void display(heap h);

#endif

