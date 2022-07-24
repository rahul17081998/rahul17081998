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
// DFS
void DFSrec(vector<int> adj[],int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(int u:adj[s])
    {
        if(visited[u]==false)
        {
            DFSrec(adj,u,visited);
        }
    }
}
void DFS(vector<int> adj[], int v, int s)
{
    bool visited[v+1];
    for (int i = 0; i < v; i++) {visited[i]=false;}
    
    DFSrec(adj,s,visited);
}

// print graph
void printGraph(vector<int> adj[],int v)
{
    for (int i = 0; i < v; i++)
    {
        cout<<i<<" : ";
        for(int x:adj[i])
            cout<<x<<" ";
        cout<<"\n";
    }
    
}

int main(){
    int v=7;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,0,4);
    addEdge(adj,4,5);
    addEdge(adj,4,6);
    printGraph(adj,v);
    int s=1; // source
    cout<<endl;
    DFS(adj,v,s);
    return 0;
}