#include<stdio.h>
#include<stdlib.h>

typedef struct Bnode{
    double data;
    struct Bnode* next;
} bnode;

int Nbucket = 10;
int interval = 10;

int getIdx(int n){
    return(n*interval);
}

void printBuckets(bnode* head){
    bnode* temp = head;

    while(temp != NULL){
        printf("%lf ->",temp->data);
        temp = temp->next;
    }
}

bnode* insert_Sorted(bnode* shead , bnode* cur){
    if(shead == NULL || shead->data >= cur->data){
        cur->next = shead;
        shead = cur;
        return cur;
    }
    else{
        bnode* temp = shead;

        while((temp->next != NULL) && (temp->next->data < cur->data)){
            temp = temp->next;
            cur->next = temp->next;
            temp->next = cur;
        }

        return shead;
    }
}

bnode* insertionSort_ll(bnode* head){
    //Insertion Sort linked list

    bnode* cur = head;
    bnode* shead = NULL;

    while(cur != NULL){
        bnode* next = cur->next;
        shead = insert_Sorted(shead,cur);
        cur = next;        
    }

    return shead;
}

void bucketSort(double *arr,int n){

    bnode** buc = (bnode**)malloc(sizeof(bnode*)*Nbucket);

    for(int i = 0 ; i < Nbucket ; i++){
        buc[i] = NULL;
    }

    for(int i = 0 ; i < n ; i++){
        int pos = getIdx(arr[i]);

        bnode* cur = (bnode*)malloc(sizeof(bnode));
        cur->data = arr[i];
        cur->next = buc[pos];
        buc[pos] = cur;
    }

    //print buckets
    for(int i = 0 ; i < Nbucket ; i++){
        printf("Bucket[%d] = ",i);
        printBuckets(buc[i]);
        printf("\n");
    }

    for(int i = 0 ; i < Nbucket ; i++){
        buc[i] = insertionSort_ll(buc[i]);
    }

    //print buckets(After Sorting)
    for(int i = 0 ; i < Nbucket ; i++){
        printf("Bucket[%d] = ",i);
        printBuckets(buc[i]);
        printf("\n");
    }

    int j = 0;

    for(int i = 0 ; i < Nbucket ; i++){
        bnode* temp = buc[i];

        while(temp != NULL){
            arr[j++] = temp->data;
            temp = temp->next;
        }
    }
}

int main(){

    int n;
    scanf("%d",&n);
    double arr[n];

    for(int i = 0 ; i < n ; i++){
        scanf("%lf",&arr[i]);
    }

    bucketSort(arr,n);

    for(int i = 0 ; i < n ; i++){
        printf("%lf ",arr[i]);
    }
    puts("");

    return 0;
}