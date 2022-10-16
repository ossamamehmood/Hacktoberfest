#include<stdio.h>
#include<stdlib.h>
#define n 4
#define inf 999

void display(int dist[][n]){
    // printf ("The following matrix shows the shortest distances"
    //         " between every pair of vertices \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (dist[i][j] == 999)
                printf("inf\t");
            else
                printf ("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}



void floyd(int graph[][n]){
    int i,j,k,dist[n][n],p[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dist[i][j]=graph[i][j];
            p[i][j]=i;
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
        printf("\nD%d:\n",k);
        display(dist);
    }
    // display(dist);
}

int main()
{
    int graph[n][n] = { {0, 10, 5, 3},
						{1, 0, inf, inf},
						{inf, 2, 0, inf},
						{inf, inf, 2, 0}
					};
    floyd(graph);
    return 0;
}