#include<stdio.h>
#include<stdlib.h>

//Using Adjacency List

typedef struct gNode{
    int val;
    struct gNode* next;
} gnode;

typedef struct Graph{
    int num_vertex;
    struct gNode** adjList;
} graph;

typedef struct Snode{
    int data;
    struct Snode* next;
} snode;

typedef struct Qnode{
    int data;
    struct Qnode* next;
} qnode;

qnode* enqueue(qnode* head, int n){
    qnode* temp = (qnode *)malloc(sizeof(qnode));
    temp->data = n;
    temp->next = NULL;

    if(head == NULL){
        return temp;
    }

    qnode* test = head;

    while(test->next != NULL){
        test = test->next;
    }

    test->next = temp;

    return head;
}

qnode* dequeue(qnode* head){
    if(head == NULL){
        puts("Queue Underflow !!");
        return head;
    }

    qnode* del;

    if(head->next == NULL){
        del = head;
        free(head);
        return NULL;
    }

    del = head;
    head = head->next;
    free(del);

    return head;
}

int qpeek(qnode* head){
    if(head == NULL)    return -99;

    return head->data;
}


snode* pushS(snode* head , int val){
    snode* temp = (snode *)malloc(sizeof(snode));
    temp->data = val;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        return head;
    }

    snode* test = head;

    while(test->next != NULL){
        test = test->next;
    }

    test->next = temp;

    return head;
}

snode* popS(snode* head){
    if(head == NULL){
        puts("Stack Underflow !!");
        return head;
    }

    snode* del ;

    if(head->next == NULL){
        del = head;
        free(del);
        return NULL;
    }

    snode* test = head;

    while(test->next->next != NULL){
        test = test->next;
    }

    del = test->next;
    test->next = NULL;
    free(del);

    return head;
}

int peekS(snode* head){
    snode* temp = head;

    if(head == NULL){
        return -99;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    return temp->data;
}

gnode* createNode(int d){
    gnode* newnode = (gnode *)malloc(sizeof(gnode));
    newnode->val = d;
    newnode->next = NULL;
    
    return newnode;
}

graph* createGraph(int num){
    graph* newgraph = (graph *)malloc(sizeof(graph));

    newgraph->num_vertex = num;

    newgraph->adjList = (gnode **)malloc(num*sizeof(gnode));

    for(int i = 0 ; i < num ; i++){
        newgraph->adjList[i] = NULL;
    }

    return newgraph;
}

void addEdge(graph* gp , int a , int b){
    gnode* newnode = (gnode *)malloc(sizeof(gnode));
    newnode = createNode(b);
    newnode->next = gp->adjList[a];
    gp->adjList[a] = newnode;

    newnode = createNode(a);
    newnode->next = gp->adjList[b];
    gp->adjList[b] = newnode;
}

void printGraph(graph* gp){

    for(int i = 0 ; i < gp->num_vertex ; i++){
        gnode* temp = gp->adjList[i];
        
        printf("Vertex %d : ",i);
        while(temp != NULL){
            printf("%d -> ",temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

int checkInAry(int* arr, int n,int d){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == d) return 1;
    }

    return 0;
}

void DFS(graph* gph , int start){
    int n = gph->num_vertex;
    int arr[n];

    for(int i = 0 ; i < n ; i++){
        arr[i] = -1;
    }

    snode* head = NULL;
    int k = 0;
    int visit = start;

    gnode* temp = gph->adjList[start];
    arr[k++] = visit;

    while(temp != NULL){
        head = pushS(head,temp->val);
        temp = temp->next;
    }

    while(head != NULL){
        visit = peekS(head);

        if(!checkInAry(arr,n,visit)){
            arr[k++] = visit;

            head = popS(head);

            temp = gph->adjList[visit];

            while(temp != NULL){
                int numb = temp->val;

                if(!checkInAry(arr,n,numb)){
                    head = pushS(head,numb);
                }
                temp = temp->next;
            }
        }else{
            head = popS(head);
        }
    }

    for(int j = 0 ; j < n ; j++){
        printf("%d ",arr[j]);
    }
    puts("");    
}

void BFS(graph* gph , int start){
    int n = gph->num_vertex;
    int arr[n];

    for(int i = 0 ; i < n ; i++){
        arr[i] = -1;
    }

    qnode* head = NULL;
    int k = 0;
    int visit = start;

    gnode* temp = gph->adjList[start];
    arr[k++] = visit;

    while(temp != NULL){
        head = enqueue(head,temp->val);
        temp = temp->next;
    }

    while(head != NULL){
        visit = qpeek(head);

        if(!checkInAry(arr,n,visit)){
            arr[k++] = visit;

            head = dequeue(head);

            temp = gph->adjList[visit];

            while(temp != NULL){
                int numb = temp->val;

                if(!checkInAry(arr,n,numb)){
                    head = enqueue(head,numb);
                }
                temp = temp->next;
            }
        }else{
            head = dequeue(head);
        }
    }

    for(int j = 0 ; j < n ; j++){
        printf("%d ",arr[j]);
    }
    puts("");    
}

int main(){

    graph* head = createGraph(7);
    addEdge(head,0,1);
    addEdge(head,0,2);
    addEdge(head,0,3);
    addEdge(head,2,1);
    addEdge(head,2,4);
    addEdge(head,1,2);
    addEdge(head,4,2);
    addEdge(head,1,5);
    addEdge(head,5,6);

    printGraph(head);

    puts("DFS :- ");
    DFS(head,0);

    puts("BFS :- ");
    BFS(head,0);
    
    return 0;
}