#include <bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int source;
    int destination;
    int weight;

};

bool compare(Edge e1,Edge e2)
{
    return (e1.weight<e2.weight);
}

int find(int v,int *parents)
{
    if(parents[v]==v)
    {
        return v;
    }
    return find(parents[v], parents);
}

bool Union(Edge *output,Edge *input,int v,int *parents)
{
    int count=0,i=0;
    while(count<v-1)
    {
        int parentS=find(input[i].source,parents);
        int parentD=find(input[i].destination,parents);
        if(parentS!=parentD)
        {
            output[count]=input[i];
            count++;
            parents[parentS]=parents[parentD];
        }
        i++;
    }
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    Edge *input=new Edge[e];
    for(int i=0;i<e;i++)
    {
        cin>>input[i].source>>input[i].destination>>input[i].weight;
    }

    sort(input,input+e,compare);

    int *parents=new int[v];
    for(int i=0;i<v;i++)
    {
        parents[i]=i;
    }
    Edge *output=new Edge[v-1];
    Union(output,input,v,parents);

    for(int i=0;i<v-1;i++)
    {
        cout<<min(output[i].source,output[i].destination)<<" "<<max(output[i].source,output[i].destination)<<" "<<output[i].weight<<endl;
    }
}
