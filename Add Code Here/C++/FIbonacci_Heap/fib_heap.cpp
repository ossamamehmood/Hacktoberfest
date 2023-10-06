#include<iostream>
#include<cstdbool>
#include <bits/stdc++.h>
#include "fib_heap.hpp"

using namespace std;

// Function to init heap
void initHeap(heap *h){

    if(!h)
        return;

    h->n = h->potential = h->degree = 0;
    h->min = NULL;

    return;
}

// Function to init node
node* initNode(int val){

    node *newNode = new node;
    newNode->key = val;
    newNode->degree = 0;
    newNode->parent = newNode->child = NULL;
    newNode->mark = false;
    newNode->left = newNode->right = newNode;

    return newNode;
}

// Function to insert key into the heap
void insert(heap *h, int val){

    if(!h)
        return;

    node *newNode = initNode(val);

    if(!(h->min)){
        h->min = newNode;
        (h->n)++;
        (h->potential)++;
        return;
    }

    h->min->left->right = newNode;
    newNode->right = h->min;
    newNode->left = h->min->left;
    h->min->left = newNode;

    if(h->min->key > newNode->key)
        h->min = newNode;

    (h->n)++;
    (h->potential)++;

    return;
}

// Function to do union of two heaps
heap* unionOfHeaps(heap *h1, heap *h2){

    if(!h1 || !(h1->min))
        return h2;
    if(!h2 || !(h2->min))
        return h1;

    heap *res = new heap;
    initHeap(res);

    res->min = h1->min;

    node *p, *q;
    p = res->min->right;
    q = h2->min->left;

    res->min->right->left = h2->min->left;
    res->min->right = h2->min;
    h2->min->left = res->min;
    q->right = p;

    if(h2->min->key < res->min->key)
        res->min = h2->min;

    res->n = h1->n + h2->n;

    return res;
}

// Function to merge two trees
void merge(heap *h, node *n1, node *n2){

    if(!h || !n1 || !n2)
        return;

    n2->right->left = n2->left;
    n2->left->right = n2->right;

    if(n1->right == n1)
        h->min = n1;

    n2->left = n2;
    n2->right = n2;
    n2->parent = n1;

    if(!(n1->child))
        n1->child = n2;

    n2->right = n1->child;
    n2->left = n1->child->left;
    n1->child->left->right = n2;
    n1->child->left = n2;

    if((n2->key) < (n1->child->key))
        n1->child = n2;

    (n1->degree)++;

    return;
}

// Function to calculate degree of heap
int calculateDegree(int n){

    int deg = 0;

    while(n > 1){
        deg++;
        n = n/2;
    }
    return deg;

}

// Consolidte heap
void consolidate(heap *h){

    if(!h)
        return;

    int degree = calculateDegree(h->n);
    h->degree = degree;

    node *arr[degree + 1];

    for(int i = 0; i <= degree; i++){
        arr[i] = NULL;
    }

    node *p, *q, *temp;
    int deg;

    p = h->min;

    do{
        deg = p->degree;

        while(arr[deg]){

            q = arr[deg];

            if(p->key > q->key){

                temp = p;
                p = q;
                q = temp;
            }

            if(q == h->min)
                h->min = p;

            merge(h, p, q);

            if(q->right == p)
                h->min = p;

            arr[deg] = NULL;
            deg++;
        }
        arr[deg] = p;
        p = p->right;

    }while(p != h->min);

    h->min = NULL;

    for(int i = 0; i <= degree; i++){

        if(arr[i]){

            arr[i]->left = arr[i]->right = arr[i];

            if(!(h->min))
                h->min = arr[i];
            else{
                h->min->left->right = arr[i];
                arr[i]->right = h->min;
                arr[i]->left = h->min->left;
                h->min->left = arr[i];

                if(arr[i]->key < h->min->key)
                    h->min = arr[i];
            }
        }
    }
    return;
}

// Function to find the node
node* findNode(node* h, int key){

    node *x, *temp;

    if(!h || (h->key > key))
        return NULL;

    for(x = h; ; x = x->right){

        if(x->key == key)
            return x;

        if(x->child && (x->key < key)){
            temp = findNode(x->child, key);
            if(temp)
                return temp;
        }

        if(x->right == h)
            break;
    }

    return NULL;
}

// Function to print the heap
void printHeap(heap h){

    node *curr, *temp, *p;

    curr = h.min;

    if(!curr){
        cout << "Heap is empty" << endl << endl;
        return;
    }

    queue<node*> q;

    do{
        q.push(curr);

        cout << "[ ";

        while(!q.empty()){

            temp = q.front();
            q.pop();

            if(temp->mark)
                cout << "\033[31m" << temp->key << " " << "\033[33m";
            else
                cout << temp->key << " ";

            if(temp->child){
                p = temp->child;
                do{

                    q.push(p);
                    p = p->right;

                }while(p != temp->child);
            }
        }
        curr = curr->right;
        cout << "]";

        if(curr != h.min)
            cout << " -> ";

    }while(curr != h.min);

    cout << endl << endl <<  "Marked nodes are displayed in red color." << endl << endl;

    return;
}

// Function to extract min from heap
node* extractMin(heap *h){

    if(!h || !(h->min))
        return NULL;

    node *p, *q, *temp;

    p = q = h->min;
    temp = NULL;

    if(p == p->right && !(p->child)){
        h->min = NULL;
        return NULL;
    }

    if(p->child){

        temp = p->child;
        do{
            q = temp->right;
            h->min->left->right = temp;
            temp->right = h->min;
            temp->left = h->min->left;
            h->min->left = temp;
            temp->parent = NULL;
            temp = q;
        }while(q != p->child);
    }

    p->left->right = p->right;
    p->right->left = p->left;

    h->min = p->right;
    p = q = h->min;

    do{
        if(p->key < h->min->key)
            q = p;
        p = p->right;
    }while(p != h->min);

    h->min = q;

    consolidate(h);

    (h->n)--;

    h->potential = totalrootNodes(h->min) + 2 * totalMarkedNodes(h->min);

    return p;
}

// Function to cut the decresed node
void cut(heap *h, node *target){

    if(!h || !(h->min) || !target || !(target->parent))
        return;

    if(target == target->right)
        target->parent->child = NULL;
    else
        target->parent->child = target->right;

    (target->parent->degree)--;

    target->left->right = target->right;
    target->right->left = target->left;

    target->left = target;
    target->right = target;
    h->min->left->right = target;
    target->right = h->min;
    target->left = h->min->left;
    h->min->left = target;

    target->parent = NULL;
    target->mark = false;

    return;
}

// Function to cascading cut the decreased node
void cascadingCut(heap *h, node *parent){

    if(parent->parent){

        if(!(parent->mark))
            parent->mark = true;
        else{
            cut(h, parent);
            cascadingCut(h, parent->parent);
        }
    }
    return;
}

// Function to do melding
void meld(heap *h, node* target){

    node *parent = target->parent;
    cut(h, target);
    cascadingCut(h, parent);

    return;
}

// Function to decrease key
void decreaseKey(heap *h, node *target, int val){

    if(!h || !(h->min) || !target)
        return;

    if(target->key <= val)
        return;

    target->key = val;

    if(target->parent && (target->key < target->parent->key))
        meld(h, target);

    if(target->key < h->min->key)
        h->min = target;

    h->potential = totalrootNodes(h->min) + 2 * totalMarkedNodes(h->min);

    return;
}

// Function to calculate total marked nodes
int totalMarkedNodes(node* h){

    if(!h)
        return 0;

    node *temp;
    int count = 0;

    for(temp = h; ; temp = temp->right){

        if(temp->mark)
            count++;

        if(temp->child)
            count += totalMarkedNodes(temp->child);

        if(temp->right == h)
            break;
    }

    return count;
}

// Function to calculate total root nodes
int totalrootNodes(node* h){

    if(!(h))
        return 0;

    int count = 0;

    node* temp;

    for(temp = h; ; temp = temp->right){

        count++;

        if(temp->right == h)
            break;
    }
    return count;
}

// Function to display root nodes, heap, potential etc
void display(heap h){

    if(!(h.min)){
        cout << "Heap is empty" << endl;
        return;
    }

    cout << "Roots : ";
    node *temp = h.min;

    do{
        cout << temp->key << " ";
        temp = temp->right;
    }while(temp != h.min);

    cout << endl << endl << "Heap : ";
    printHeap(h);

    cout << "Potential : " << h.potential << endl << endl;
    cout << "Degree of Heap : " << h.degree  << endl << endl;

    return;

}
