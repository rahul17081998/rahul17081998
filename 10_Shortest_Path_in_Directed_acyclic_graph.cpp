// Shortest path in directed acyclic graph
// Topological sorting using BFS algorithm
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Add an edge in graph using list 
// insert edges in directed way
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
// Detect cycle in directed graph
void topologicalSorting(vector<int>adj[],vector<int> &tarr,int V)
{
    vector<int>in_degree(V,0);
    // calculate in-degree of nodes
    for (int i = 0; i < V; i++)
    {
        for(int u:adj[i])
            in_degree[u]++;
    }
    queue<int> q;
    // initially insert nodes into queue if in-degree is 0
    for (int i = 0; i < V; i++)
    {
        if(in_degree[i]==0)
            q.push(i);
    }
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        // cout<<u<<" ";
        tarr.push_back(u);
        for(int v:adj[u])
        {
            in_degree[v]--;
            if(in_degree[v]==0)
                q.push(v);
        }
    } 
}
// print graph
void printGraph(vector<int> adj[],int v)
{
    cout<<"S :\t D"<<endl<<endl;
    for (int i = 0; i < v; i++)
    {
        cout<<i<<" : \t";
        for(int x:adj[i])
            cout<<x<<" ";
        cout<<"\n";
    }
    
}

int main(){
    int v=5;
    vector<int> adj[v];
    
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
   
    // printGraph(adj,v);
    vector<int> tar;
    topologicalSorting(adj,tar,v);
    cout<<"Topological sorting of the graph\n";
    for(int x:tar)
        cout<<x<<" ";
    
   
    
    
    return 0;
}