#ifndef _BINOMIAL_HEAP_H_
#define _BINOMIAL_HEAP_H_

typedef int Type;

typedef struct _BinomialNode{
    Type   key;                        //  Keyword (key value)
    int degree;                        //  degree
    struct _BinomialNode *child;    //  Left child
    struct _BinomialNode *parent;    //  Parent node
    struct _BinomialNode *next;        //  brothers
}BinomialNode, *BinomialHeap;

//  Create the node corresponding to the new key and insert it into the binomial heap.
BinomialNode* binomial_insert(BinomialHeap heap, Type key);
//  Delete node: delete the node whose key value is key, and return to the binary tree after deleting the node
BinomialNode* binomial_delete(BinomialHeap heap, Type key);
//  Update the key value oldkey of the binomial heap to newkey
void binomial_update(BinomialHeap heap, Type oldkey, Type newkey);

//  Merge binomial heap: merge h1, h2 into one heap and return the merged heap
BinomialNode* binomial_union(BinomialHeap h1, BinomialHeap h2) ;

//  Find: Find the node whose key value is key in the binomial heap
BinomialNode* binomial_search(BinomialHeap heap, Type key);
//  Get the smallest node in the binomial heap
BinomialNode* binomial_minimum(BinomialHeap heap) ;
//  Remove the smallest node and return to the binomial heap after removing the node
BinomialNode* binomial_extract_minimum(BinomialHeap heap);

//  Print "binary pile"
void binomial_print(BinomialHeap heap);

#endif
