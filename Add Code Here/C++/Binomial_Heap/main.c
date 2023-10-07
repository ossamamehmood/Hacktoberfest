#include <stdio.h>
#include "binomial_heap.h"

/*#define DEBUG 1

#if DEBUG
#define log(x, ...)   printf(x, __VA_ARGS__)
#else
#define log(x, ...)
#endif
*/
#define LENGTH(a) ( (sizeof(a)) / (sizeof(a[0])) )

//  7 in total = 1+2+4
int a[] = {12,  7, 25, 15, 28,
           33, 41, 50};
//  A total of 13 = 1+4+8
int b[] = {18, 35, 20, 42,  9,
           31, 23,  6, 48, 11,
           24, 52, 13 };
//  Verify "insert operation of binomial heap"
void test_insert()
{
    int i;
    int alen=LENGTH(a);
    BinomialHeap ha=NULL;

    //  Binomial ha
    printf("== Binomial heap (ha) is added sequentially: ");
    for(i=0; i<alen; i++)
    {
        printf("%d ", a[i]);
        ha = binomial_insert(ha, a[i]);
    }
    printf("\n");
    //  Print binomial stack ha
    printf("== Binomial heap (ha) detailed information: \n");
    binomial_print(ha);
}

//  Verify "binary heap merge operation"
void test_union()
{
    int i;
    int alen=LENGTH(a);
    int blen=LENGTH(b);
    BinomialHeap ha,hb;

    ha=hb=NULL;

    //  Binomial ha
    printf("== Binomial heap (ha) is added sequentially: ");
    for(i=0; i<alen; i++)
    {
        printf("%d ", a[i]);
        ha = binomial_insert(ha, a[i]);
    }
    printf("\n");
    printf("== Binomial heap (ha) detailed information: \n");
    binomial_print(ha); //  Print binomial stack ha

    //  Binomial heap hb
    printf("== Binomial heap (hb) is added sequentially: ");
    for(i=0; i<blen; i++)
    {
        printf("%d ", b[i]);
        hb = binomial_insert(hb, b[i]);
    }
    printf("\n");
    printf("== Details of Binomial Heap (hb): \n");
    binomial_print(hb); // Print binomial heap hb

    //  Combine the "binary pile hb" into the "binary pile ha".
    ha = binomial_union(ha, hb);
    printf("== Detailed information after merging ha and hb:\n");
    binomial_print(ha); //  Print the detailed information of the binomial ha
}

//  Verify "Delete Operation of Binary Heap"
void test_delete()
{
    int i;
    int blen=LENGTH(b);
    BinomialHeap hb=NULL;

    //  Binomial heap hb
    printf("== Binomial heap (hb) is added sequentially: ");
    for(i=0; i<blen; i++)
    {
        printf("%d ", b[i]);
        hb = binomial_insert(hb, b[i]);
    }
    printf("\n");
    printf("== Details of Binomial Heap (hb): \n");
    binomial_print(hb); //  Print binomial heap hb

    //  Delete the node in the binomial heap hb
    i = 20;
    hb = binomial_delete(hb, i);
    printf("== Detailed information after deleting node %d: \n", i);
    binomial_print(hb); //  Print binomial heap hb
}

//  Verify the "update (reduce) operation of the binomial heap"
void test_decrease()
{
    int i;
    int blen=LENGTH(b);
    BinomialHeap hb=NULL;

    //  Binomial heap hb
    printf("== Binomial heap (hb) is added sequentially: ");
    for(i=0; i<blen; i++)
    {
        printf("%d ", b[i]);
        hb = binomial_insert(hb, b[i]);
    }
    printf("\n");
    printf("== Details of Binomial Heap (hb): \n");
    binomial_print(hb); //  Print binomial heap hb

    //  Update node 20 to 2
    binomial_update(hb, 20, 2);
    printf("== Update detailed information after node 20->2: \n");
    binomial_print(hb); //  Print binomial heap hb
}

//  Verify the "update (add) operation of the binomial heap"
void test_increase()
{
    int i;
    int blen=LENGTH(b);
    BinomialHeap hb=NULL;

    //  Binomial heap hb
    printf("== Binomial heap (hb) is added sequentially: ");
    for(i=0; i<blen; i++)
    {
        printf("%d ", b[i]);
        hb = binomial_insert(hb, b[i]);
    }
    printf("\n");
    printf("== Details of Binomial Heap (hb): \n");
    binomial_print(hb); //  Print binomial heap hb

    //  Update node 6 to 20
    binomial_update(hb, 6, 60);
    printf("== Update detailed information after node 6->60: \n");
    binomial_print(hb); //  Print binomial heap hb
}


int main(){
    int l;
    char ch;
    do {
        printf("\nMENU:-\n");
        printf(
                "\n1)INSERT AN ELEMENT\n2)EXTRACT THE MINIMUM KEY NODE\n3)DECREASE A NODE KEY\n 4)DELETE A NODE\n5)QUIT\n");
        scanf("%d", &l);
        switch (l) {
        case 1:
                do{
                    //  1. Verify "Binary Heap Insertion Operation"
                    test_insert();
                    printf("\nINSERT MORE(y/Y)= \n");
                    fflush(stdin);
                    scanf("%c", &ch);
                }while (ch == 'Y' || ch == 'y');
                break;

        case 2:
                //  2. Verify "binary heap merge operation"
                test_union();

        case 3:
                do{
                    //  3. Verify "Delete operation of binomial heap"
                    test_delete();

                    printf("\nDelete MORE(y/Y)= \n");
                    fflush(stdin);
                    scanf("%c", &ch);
                }while (ch == 'Y' || ch == 'y');
                break;

        case 4:

                //  4. Verify the "update (reduce) operation of the binomial heap"
                test_decrease();

        case 5:
                //  5. Verify the "update (add) operation of the binomial heap"
                test_increase();
        case 6:
            printf("\nTHANK U SIR\n");
            break;
        default:
            printf("\nINVALID ENTRY...TRY AGAIN....\n");
        }
    } while (l != 6);
}
