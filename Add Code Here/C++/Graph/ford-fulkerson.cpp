#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
#define INFINITE 999999;
class Graph
{
private:
    int no_of_vertices;
    int s_source;
    int t_sink;
    bool flag_anti_par_edge;
    vector<vector<int>> adj_matrix;
    vector<vector<int>> residual_matrix;
    vector<bool> visited;
    vector<int> parent;
    int max_flow=0;

    void dfs_visit(int u)
    {
        visited[u]=true;
        for(int v=0;v<no_of_vertices;v++)
        {
            if(visited[v]==false && residual_matrix[u][v] > 0)
            {
                parent[v]=u;
                dfs_visit(v);
            }
        }
    }
    bool dfs()
    {
        bool flag=false;
        for(int i=0;i<no_of_vertices;i++)
        {
            visited.at(i)=false;
            parent.at(i)=-1;
        }
        dfs_visit(0);
        if(visited[t_sink]==true)
        {
            flag=true;
        }
        return flag;
    }

public:
    Graph(int v)
    {
        no_of_vertices=v;
        s_source=0;
        t_sink=no_of_vertices-1;
        flag_anti_par_edge=false;
        for(int i=0;i<no_of_vertices;i++)
        {
            vector<int> vec;
            for(int j=0;j<no_of_vertices;j++)
            {
                vec.push_back(0);
            }
            adj_matrix.push_back(vec);
            visited.push_back(false);
            parent.push_back(-1);
        }
    }
    int resolve_anti_parallel_edge_issue()
    {
        int count=0;
        for(int i=0;i<no_of_vertices;i++)
        {
            for(int j=0;j<no_of_vertices;j++)
            {
                if(adj_matrix[i][j]!=0 && adj_matrix[j][i]!=0)
                {
                    count++;
                }
            }
        }
        count=count/2;
        if(count>0)
        {
            flag_anti_par_edge=true;
        }
        for(int i=0;i<no_of_vertices;i++)
        {
            for(int j=0;j<count;j++)
            {
                adj_matrix[i].push_back(0);
            }
        }
        for(int i=0;i<count;i++)
        {
            vector<int> ve;
            for(int j=0;j<no_of_vertices+count;j++)
            {
                ve.push_back(0);
            }
            adj_matrix.push_back(ve);
            visited.push_back(false);
            parent.push_back(-1);
        }
        int k=no_of_vertices;
        for(int i=0;i<no_of_vertices+count;i++)
        {
            for(int j=0;j<no_of_vertices+count;j++)
            {
                if(adj_matrix[i][j]!=0 && adj_matrix[j][i]!=0)
                {
                    adj_matrix.at(i).at(k)=adj_matrix[i][j];
                    adj_matrix.at(k).at(j)=adj_matrix[i][j];
                    adj_matrix.at(i).at(j)=0;
                    k++;
                }
            }
        }
        no_of_vertices+=count;
        return count;
    }
    void push_edge(int val_u,int val_v,int cap_el)
    {
        adj_matrix.at(val_u).at(val_v)=cap_el;
    }
    void show_graph()
    {
        for(int i=0;i<no_of_vertices;i++)
        {
            for(int j=0;j<no_of_vertices;j++)
            {
                cout<<setw(5)<<adj_matrix[i][j];
            }
            cout<<endl;
        }
    }
    int ford_fulkerson()
    {
        int count=resolve_anti_parallel_edge_issue();
        if(flag_anti_par_edge==true)
        {
            if(count==1)
            {
                cout<<"There was "<<count<<" anti parallel edge, which is now resolved"<<endl;
            }
            else
            {
                cout<<"There were "<<count<<" anti parallel edges, which are now resolved"<<endl;
            }
        }
        else
        {
            cout<<"There were no anti parallel edges"<<endl;
        }
        int u,v;
        residual_matrix=adj_matrix;
        int aug_path_flow;
        while(dfs()!=false)
        {
            aug_path_flow=INFINITE;
            for(v=t_sink;v>0;v=parent[v])
            {
                u=parent[v];
                aug_path_flow=min(aug_path_flow,residual_matrix[u][v]);    
            }
            for(v=t_sink;v>0;v=parent[v])
            {
                u=parent[v];
                residual_matrix.at(u).at(v)=residual_matrix[u][v]-aug_path_flow;
                residual_matrix.at(v).at(u)=residual_matrix[v][u]+aug_path_flow;
            }
            max_flow+=aug_path_flow;
        }
        return max_flow;
    }
};
int main()
{
    int v,e;
    int val_u,val_v,cap_el;
    cout<<"Enter the total number of vertices= ";
    cin>>v;
    cout<<"Enter the total number of edges= ";
    cin>>e;
    Graph obj(v);
    cout<<"The vertex at position 0 will be the source and the vertex at position "<<v-1<< " will be the sink for this flow network"<<endl;
    cout<<"Now enter the edges as, source vertex, destination vertex, capacity of the edge"<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>val_u;
        cin>>val_v;
        cin>>cap_el;
        obj.push_edge(val_u,val_v,cap_el);
    }
    cout<<"The adjacency matrix reperesentation of the given directed graph is"<<endl;
    obj.show_graph();
    int res=obj.ford_fulkerson();
    cout<<"The maximum flow for the given directed graph is= "<<res<<endl;
    return 0;
}