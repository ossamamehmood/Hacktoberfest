#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include<string.h> 

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int* arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getParentIndex(int i) {
    return (i - 1) / 2;
}

int getLeftChildIndex(int i) {
    return 2 * i + 1;
}

int getRightChildIndex(int i) {
    return 2 * i + 2;
}

void heapifyUp(MinHeap* heap, int index) {
    int parentIndex = getParentIndex(index);
    while (index > 0 && heap->arr[index] < heap->arr[parentIndex]) {
        swap(&heap->arr[index], &heap->arr[parentIndex]);
        index = parentIndex;
        parentIndex = getParentIndex(index);
    }
}

void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int leftChildIndex = getLeftChildIndex(index);
    int rightChildIndex = getRightChildIndex(index);

    if (leftChildIndex < heap->size && heap->arr[leftChildIndex] < heap->arr[smallest])
        smallest = leftChildIndex;

    if (rightChildIndex < heap->size && heap->arr[rightChildIndex] < heap->arr[smallest])
        smallest = rightChildIndex;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(MinHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        // printf("Heap is full, cannot insert any more elements.\n");
        return;
    } 

    heap->arr[heap->size++] = value;
    heapifyUp(heap, heap->size - 1);
}

int extractMin(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty, cannot extract minimum.\n");
        return -1;
    }

    int minValue = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return minValue;
}


void printHeap(MinHeap* heap) {
    printf("Min Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}



int findNthUglyNumber(int n) {
    if (n <= 0) return 0;

    MinHeap* heap = createMinHeap(n);
    int uglyNum = 1;

    insert(heap, uglyNum);


    int size = 100*n;
    bool *flag =(bool *)malloc(size * sizeof(bool));
    memset(flag,0,size*sizeof(bool));
    flag[1]=true;

    for (int i = 1; i <= n; i++) {
        uglyNum = extractMin(heap);

        int m2 =2 * uglyNum;
        int m3 = 3 * uglyNum;
        int m5 = 5 * uglyNum;

        if(flag[m2]==false)
        {
            flag[m2]=true;
            insert(heap,m2);
        }

        if(flag[m3]==false)
        {
            flag[m3]=true;
            insert(heap,m3);
        }

        if(flag[m5]==false)
        {
            flag[m5]=true;
            insert(heap,m5);
        }        
    }

    free(heap->arr);
    free(heap);
    return uglyNum;
}

int main() {
   
        int n ;
        printf("enter the number ");
        scanf("%d",&n);
        int nthUglyNum = findNthUglyNumber(n);
        printf("The %dth ugly number is: %d\n", n, nthUglyNum);

      
    return 0;
}