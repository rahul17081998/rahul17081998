#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Add an edge in graph using list 
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// Detect cycle in undirected graph
bool DFSRec(vector<int>adj[],int s,bool visited[],int parent)
{
    visited[s]=true;
    for(int u:adj[s])
    {
        if(visited[u]==false)
        {
            if(DFSRec(adj,u,visited,s)==true)
                return true;
        }
        else if(u!=parent)
            return true;
    }
    return false;
}
bool isCycle(vector<int>adj[],int v)
{
    bool visited[v];
    for (size_t i = 0; i < v; i++)
    {
        visited[i]=false;
    }
    for (int i = 0; i < v; i++)
    {
        if(visited[i]==false)
        {
            if(DFSRec(adj,i,visited,-1)==true)
                return true;
        }
    }
    return false;
    
    
}
// print graph
void printGraph(vector<int> adj[],int v)
{
    for (int i = 0; i < v; i++)
    {
        for(int x:adj[i])
            cout<<x<<" ";
        cout<<"\n";
    }
    
}

int main(){
    int v=5;
    vector<int> adj[v];
    // cycle is present for below input
    // addEdge(adj,0,1);
    // addEdge(adj,0,2);
    // addEdge(adj,1,2);
    // addEdge(adj,1,3);
    // addEdge(adj,2,3);
    // addEdge(adj,2,4);

    // cycle is not present for below input
    addEdge(adj,0,1);
    addEdge(adj,1,4);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    // printGraph(adj,v);
   
    cout<<"\nIs cycle detected: "<<isCycle(adj,v)<<endl;
    
    return 0;
}