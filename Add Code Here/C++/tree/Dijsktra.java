import java.util.*;
import java.util.*;
import java.io.*;

class Dijsktra{
	int v=9;
	int minDis(int dist[],boolean sptset[])
	{
		int min=Integer.MAX_VALUE,min_index=-1;
		for(int i=0;i<v;i++)
			if(sptset[i]==false && dist[i]<=min){
				min=dist[i];
				System.out.println("i="+i+" "+min);
				min_index=i;
				
			}
			return min_index;
	}
	
	void dijshort(int graph[][],int src)
	{
		int dist[] =new int[v];
		boolean sptset[]=new boolean[v];
		for(int i=0;i<v;i++)
			dist[i]=Integer.MAX_VALUE;
		dist[src]=0;
		for(int count=0;count<v-1;count++)
		{
			System.out.println("count="+count);
			int u=minDis(dist,sptset);
			sptset[u]=true;
			for(int i=0;i<v;i++)
				if(!sptset[i] && graph[u][i]!=0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][i] < dist[i] )
					dist[i]=dist[u]+graph[u][i];
				
			for(int i=0;i<v;i++)
				System.out.print(dist[i]+" ");	
		}
		for(int i=0;i<v;i++)
			System.out.print(dist[i]+" ");
	}
	public static void main(String[] args){
		int graph[][]=new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
		Dijsktra d=new Dijsktra();
		d.dijshort(graph,0);
	}
}