/*header.h*/
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

void crea_heap(int heap[], int size);
void heapify(int heap[], int i, int size);
void swap(int *a, int *b);
void stampa(int heap[], int size);

#endif
/* function.c*/
#include "header.h"

void crea_heap(int heap[], int size)
{
    for (short i = (size / 2); i > 0; i--)
    {
        heapify(heap, i, size);
    }
}

void heapify(int heap[], int i, int size)
{
    int massimo = i;
    int son_sx = 2 * i;
    int son_dx = 2 * i + 1;

    if (heap[son_sx] > heap[massimo] && son_sx <= size)
    {
        massimo = son_sx;
    }

    if (heap[son_dx] > heap[massimo] && son_dx <= size)
    {
        massimo = son_dx;
    }

    if (massimo != i)
    {
        swap(&heap[i], &heap[massimo]);
        heapify(heap, massimo, size);
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void stampa(int heap[], int size)
{
    for (short i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
}
/*main.c*/
#include "header.h"
int main()
{
    int size = 10;
    int heap[] = {-1, 2, 6, 18, 3, 42, 12, 55, 44, 94, 79};
    crea_heap(heap, size);
    stampa(heap, size);
    return 0;
}
