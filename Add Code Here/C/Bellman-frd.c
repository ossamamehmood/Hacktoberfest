#include <stdio.h>
int Bellman_Ford(int G[100][100] , int V, int E, int
edge[100][2]) {
int i,u,v,k,distance[100],S,flag=1;
for(i=0;i<V;i++)
distance[i] = 1000 ;
printf("\nEnter source : ");
scanf("%d",&S);
distance[S-1]=0;
for(i=0;i<V-1;i++){
for(k=0;k<E;k++){
u = edge[k][0];
v = edge[k][1];
if(distance[u]+G[u][v] < distance[v])
distance[v] = distance[u] + G[u][v];
}
}
for(k=0;k<E;k++){
u = edge[k][0];
v = edge[k][1] ;
if(distance[u]+G[u][v] < distance[v])
flag = 0 ;
}
if(flag)
for(i=0;i<V;i++)
printf("\nDistance from source %d to vertex %d is %d",S,(i+1),distance[i]);
//cout<<"\nDistance from source " <<S << " to vertex "<< i+1<< " is "<<distance[i];
return flag;
}
int main()
{
int V,edge[100][2],G[100][100],i,j,k=0;
printf("Enter no. of vertices: ");
scanf("%d",&V);
printf("Enter graph in matrix form:\n");
for(i=0;i<V;i++)
for(j=0;j<V;j++)
{
scanf("%d",&G[i][j]);
if(G[i][j]!=0)
edge[k][0]=i,edge[k++][1]=j;
}
if(Bellman_Ford(G,V,k,edge))
//cout<<"\nNo negative weight cycle exists\n";
return 0;
}   