#include <stdio.h>
#include <stdlib.h>
#include "binomial_heap.h"

#define swap(a,b) (a^=b,b^=a,a^=b)

/*
   * Find: Find the node whose key value is key in the binomial heap
 */
BinomialNode* binomial_search(BinomialHeap heap, Type key)
{
    BinomialNode *child;
    BinomialNode *parent = heap;

    parent = heap;
    while (parent != NULL)
    {
        if (parent->key == key)
            return parent;
        else
        {
            if((child = binomial_search(parent->child, key)) != NULL)
                return child;
            parent = parent->next;
        }
    }

    return NULL;
}

/*
   * Get the smallest root node in the binomial heap (*y)
 *
   * Parameter Description:
   * heap - Binary heap
   * prev_y - [output parameter] the previous root node of the smallest root node y
   * y - [output parameter] the smallest root node
 */
static void _binomial_minimum(BinomialHeap heap,
        BinomialNode **prev_y, BinomialNode **y)
{
    BinomialNode *x, *prev_x;    //  x is the current node used to traverse

    if (heap==NULL)
        return ;

    prev_x  = heap;
    x       = heap->next;
    *prev_y = NULL;
    *y      = heap;
    //  Find the smallest node
    while (x != NULL) {
        if (x->key < (*y)->key) {
            *y = x;
            *prev_y = prev_x;
        }
        prev_x = x;
        x = x->next;
    }
}

BinomialNode* binomial_minimum(BinomialHeap heap)
{
    BinomialNode *prev_y, *y;

    _binomial_minimum(heap, &prev_y, &y);

    return y;
}

/*
   * Merge two binomial heaps: merge child into heap
 */
static void binomial_link(BinomialHeap child, BinomialHeap heap)
{
    child->parent = heap;
    child->next   = heap->child;
    heap->child = child;
    heap->degree++;
}

/*
   * Combine the root tables in h1, h2 into a linked list with increasing degrees, and return the combined root node
 */
static BinomialNode* binomial_merge(BinomialHeap h1, BinomialHeap h2)
{
    BinomialNode* head = NULL; //heap refers to the root node of the new heap
    BinomialNode** pos = &head;

    while (h1 && h2)
    {
        if (h1->degree < h2->degree)
        {
            *pos = h1;
            h1 = h1->next;
        }
        else
        {
            *pos = h2;
            h2 = h2->next;
        }
        pos = &(*pos)->next;
    }
    if (h1)
        *pos = h1;
    else
        *pos = h2;

    return head;
}

/*
   * Merge binomial heap: merge h1, h2 into one heap, and return the merged heap
 */
BinomialNode* binomial_union(BinomialHeap h1, BinomialHeap h2)
{
    BinomialNode *heap;
    BinomialNode *prev_x, *x, *next_x;

    //  Combine the root tables in h1 and h2 into a linked list heap with increasing degrees
    heap = binomial_merge(h1, h2);
    if (heap == NULL)
        return NULL;

    prev_x = NULL;
    x      = heap;
    next_x = x->next;

    while (next_x != NULL)
    {
        if (   (x->degree != next_x->degree)
            || ((next_x->next != NULL) && (next_x->degree == next_x->next->degree)))
        {
            // Case 1: x->degree != next_x->degree
            // Case 2: x->degree == next_x->degree == next_x->next->degree
            prev_x = x;
            x = next_x;
        }
        else if (x->key <= next_x->key)
        {
            // Case 3: x->degree == next_x->degree != next_x->next->degree
            //      && x->key    <= next_x->key
            x->next = next_x->next;
            binomial_link(next_x, x);
        }
        else
        {
            // Case 4: x->degree == next_x->degree != next_x->next->degree
            //      && x->key    >  next_x->key
            if (prev_x == NULL)
            {
                heap = next_x;
            }
            else
            {
                prev_x->next = next_x;
            }
            binomial_link(x, next_x);
            x = next_x;
        }
        next_x = x->next;
    }

    return heap;
}

/*
   * New Binomial Reactor Node
 */
static BinomialNode* make_binomial_node(Type key)
{
    BinomialNode* node;

    node = (BinomialNode*)malloc(sizeof(BinomialNode));
    if (node==NULL)
    {
        printf("malloc BinomialNode failed!\n");
        return NULL;
    }

    node->key = key;
    node->degree = 0;
    node->parent = NULL;
    node->child = NULL;
    node->next = NULL;

    return node;
}

/*
   * Create the node corresponding to the key and insert it into the binomial heap.
 *
   * Parameter Description:
   * heap - the original binomial tree.
   * key - key value
   * return value:
   * Binomial tree after inserting key
 */
BinomialNode* binomial_insert(BinomialHeap heap, Type key)
{
    BinomialNode* node;

    if (binomial_search(heap, key) != NULL)
    {
        printf("insert failed: the key(%d) is existed already!\n", key);
        return heap;
    }

    node = make_binomial_node(key);
    if (node==NULL)
        return heap;

    return binomial_union(heap, node);
}

/*
   * Reverse binomial heap heap
 */
static BinomialNode* binomial_reverse(BinomialNode* heap)
{
    BinomialNode* next;
    BinomialNode* tail = NULL;

    if (!heap)
        return heap;

    heap->parent = NULL;
    while (heap->next)
    {
        next          = heap->next;
        heap->next = tail;
        tail          = heap;
        heap          = next;
        heap->parent  = NULL;
    }
    heap->next = tail;

    return heap;
}

/*
   * Remove the smallest node, and return to the binomial heap after removing the node
 */
BinomialNode* binomial_extract_minimum(BinomialHeap heap)
{
    BinomialNode *y, *prev_y;    //  y is the smallest node

    if (heap==NULL)
        return heap;

    //  Find "minimum node root y" and "its previous root node prev_y"
    _binomial_minimum(heap, &prev_y, &y);

    if (prev_y == NULL)    //  The root node of the heap is the smallest root node
        heap = heap->next;
    else                //  The root node of the heap is not the smallest root node
        prev_y->next = y->next;

    //  Reverse the left child of the smallest node to get the smallest heap child;
    //  In this way, the children of the binomial tree where the smallest node is located are all separated into an independent binomial tree (not including the smallest node)
    BinomialNode* child = binomial_reverse(y->child);
    //  Combine "delete the binomial heap child of the smallest node" and "heap".
    heap = binomial_union(heap, child);

    //  Delete the smallest node
    free(y);

    return heap;
}

/*
   * Reduce the value of the key: reduce the key value of the node node in the binomial heap to key.
 */
static void binomial_decrease_key(BinomialHeap heap, BinomialNode *node, Type key)
{
    if ((key >= node->key) || (binomial_search(heap, key) != NULL))
    {
        printf("decrease failed: the new key(%d) is existed already, \
                or is no smaller than current key(%d)\n", key, node->key);
        return ;
    }
    node->key = key;

    BinomialNode *child, *parent;
    child = node;
    parent = node->parent;
    while(parent != NULL && child->key < parent->key)
    {
        swap(parent->key, child->key);
        child = parent;
        parent = child->parent;
    }
}

/*
   * Increase the value of the key: increase the key value of the node node in the binomial heap to key.
 */
static void binomial_increase_key(BinomialHeap heap, BinomialNode *node, Type key)
{
    if ((key <= node->key) || (binomial_search(heap, key) != NULL))
    {
        printf("increase failed: the new key(%d) is existed already, \
                or is no greater than current key(%d)\n", key, node->key);
        return ;
    }
    node->key = key;

    BinomialNode *cur, *child, *least;
    cur = node;
    child = cur->child;
    while (child != NULL)
    {
        if(cur->key > child->key)
        {
            //  If "current node" <"its left child",
            //  Find the smallest node among "its children (the left child and the brother of the left child)";
            //  Then swap "the value of the smallest node" and "the value of the current node"
            least = child;
            while(child->next != NULL)
            {
                if (least->key > child->next->key)
                {
                    least = child->next;
                }
                child = child->next;
            }
            //  Exchange the value of the smallest node and the current node
            swap(least->key, cur->key);

            //  After exchanging data, adjust the "original minimum node" to make it meet the nature of the minimum heap: parent node <= child node
            cur = least;
            child = cur->child;
        }
        else
        {
            child = child->next;
        }
    }
}

/*
   * Update the key value of the node node of the binomial heap to key
 */
static void binomial_update_key(BinomialHeap heap, BinomialNode* node, Type key)
{
    if (node == NULL)
        return ;

    if(key < node->key)
        binomial_decrease_key(heap, node, key);
    else if(key > node->key)
        binomial_increase_key(heap, node, key);
    else
        printf("No need to update!!!\n");
}

/*
   * Update the key value oldkey of the binomial heap heap to newkey
 */
void binomial_update(BinomialHeap heap, Type oldkey, Type newkey)
{
    BinomialNode *node;

    node = binomial_search(heap, oldkey);
    if (node != NULL)
        binomial_update_key(heap, node, newkey);
}

/*
   * Delete node: delete the node whose key value is key, and return the binary tree after deleting the node
 */
BinomialNode* binomial_delete(BinomialHeap heap, Type key)
{
    BinomialNode *node;
    BinomialNode *parent, *prev, *pos;

    if (heap==NULL)
        return heap;

    //  Find the node whose key is key
    if ((node = binomial_search(heap, key)) == NULL)
        return heap;

    //  Move the data of the deleted node up to the root node of the binomial tree where it is located
    parent = node->parent;
    while (parent != NULL)
    {
        //  Exchange data
        swap(node->key, parent->key);
        //  Next parent node
        node   = parent;
        parent = node->parent;
    }

    //  Find the previous root node of node (prev)
    prev = NULL;
    pos  = heap;
    while (pos != node)
    {
        prev = pos;
        pos  = pos->next;
    }
    //  Remove node node
    if (prev)
        prev->next = node->next;
    else
        heap = node->next;

    heap = binomial_union(heap, binomial_reverse(node->child));

    free(node);

    return heap;
}

/*
   * Print "binary pile"
 *
   * Parameter Description:
   * node - current node
   * prev-the previous node of the current node (parent node or sibling node)
   * direction-1, which means that the current node is a left child;
   * 2, which means that the current node is a sibling node.
 */
static void _binomial_print(BinomialNode *node, BinomialNode *prev, int direction)
{
    while(node != NULL)
    {
        //printf("%2d \n", node->key);
        if (direction == 1)
            printf("\t%2d(%d) is %2d's child\n", node->key, node->degree, prev->key);
        else
            printf("\t%2d(%d) is %2d's next\n", node->key, node->degree, prev->key);

        if (node->child != NULL)
            _binomial_print(node->child, node, 1);

        //  Sibling node
        prev = node;
        node = node->next;
        direction = 2;
    }
}

void binomial_print(BinomialHeap heap)
{
    if (heap == NULL)
        return ;

    BinomialNode *p = heap;
    printf("== Binomial heap( ");
    while (p != NULL)
    {
        printf("B%d ", p->degree);
        p = p->next;
    }
    printf(") Details:\n");

    int i=0;
    while (heap != NULL)
    {
        i++;
        printf("%d. Binomial tree B%d: \n", i, heap->degree);
        printf("\t%2d(%d) is root\n", heap->key, heap->degree);

        _binomial_print(heap->child, heap, 1);
        heap = heap->next;
    }
    printf("\n");
}
