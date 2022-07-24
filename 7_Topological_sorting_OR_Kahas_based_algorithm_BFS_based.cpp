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
void topologicalSorting(vector<int>adj[],int V)
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
    // while queue is not empty
    while(q.empty()==false)
    {
        // pop one element(all elements which are in queue, indegree = 0)
        int u=q.front();
        q.pop();
        cout<<u<<" "; // print 
        // come to its adjacent 
        for(int v:adj[u])
        {   // decrease indegree by 1 for all adjacent of v
            in_degree[v]--;
            // if now indegree is 0 for adjacent of u then push into queue
            if(in_degree[v]==0)
                q.push(v);
        }
    }
    
    
}
/*
void topoSort(vector<int> adj[], int V)
{
    vector<int> in_degree(V,0);
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for(auto v:adj[i]){
            in_degree[v]++;
        }
    }
    // insert node into queue if indegree is 0
    for (int i = 0; i < V; i++)
    {
        if(in_degree[i]==0){
            q.push(i);
        }
    }
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u]){
            in_degree[v]--;
            if(in_degree[v]==0){
                q.push(v);
            }
        }

    }
    
    
}
*/
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
    cout<<"Topological sorting of the graph\n";
    topologicalSorting(adj,v);
    cout<<endl;
    // topoSort(adj,v);
   
    
    
    return 0;
}