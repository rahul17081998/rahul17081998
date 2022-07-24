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
bool isCycle(vector<int>adj[],int V)
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
    int count=0;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        // cout<<u<<" ";
        for(int v:adj[u])
        {
            in_degree[v]--;
            if(in_degree[v]==0)
                q.push(v);
            count++;
        }
    }
    return (count!=V);
    
    
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
    
    addEdge(adj,0,1);
    addEdge(adj,4,1);
    addEdge(adj,3,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
   
    // printGraph(adj,v);
    cout<<"Is cycle is present: ";
    cout<<isCycle(adj,v)<<endl;
   
    
    
    return 0;
}