#include<stdio.h>
#include<stdlib.h>

typedef struct Edge{
    int src;
    int dst;
    int wt;
}edge;

void sort(edge* edlist,int n){
    
    for(int i = 1 ; i < n ; i++){
        int j = i-1;
        edge key = edlist[i];

        while(j >= 0 && edlist[j].wt>key.wt){
            edlist[j+1] = edlist[j];
            j--;
        }
        edlist[j+1] = key;
    }
}

int findParent(int parent[],int v){
    
    if(parent[v] == v){
        return v;
    }

    return findParent(parent,parent[v]);
}

void krushkal_algo(edge* edlist,int n,int e){
    edge* opt = (edge *)malloc((n-1)*sizeof(edge));

    sort(edlist,n);

    int parent[n];

    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
    }

    int count = 0;
    
    for(int i = 0 ; (i < e) && (count < (n-1)) ; i++){
        int ps = findParent(parent,edlist[i].src);
        int pd = findParent(parent,edlist[i].dst);

        if(ps != pd){
            opt[count++] = edlist[i];
            parent[ps] = pd;
        }
    }

    for(int i = 0 ; i < n-1 ; i++){
        printf("%d %d %d\n",opt[i].src,opt[i].dst,opt[i].wt);
    }

    free(opt);
}

int main(){

    int n,e;
    scanf("%d %d",&n,&e);

    edge* edlist = (edge *)malloc(e*sizeof(edge));

    for(int i = 0 ; i < e ; i++){
        int s,d,w;
        scanf("%d %d %d",&s,&d,&w);
        edlist[i].src = s;
        edlist[i].dst = d;
        edlist[i].wt = w;
    }

    krushkal_algo(edlist,n,e);

    free(edlist);

    return 0;
}