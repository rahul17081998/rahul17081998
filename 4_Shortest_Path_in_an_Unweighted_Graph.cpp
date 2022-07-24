#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

// Add an edge in graph using list 
// create undirected graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// Shortest path in an unweighted ghaph
void shortestPath(vector<int>adj[],int s, int v)
{
    int dist[v];
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i]=false;
    }
    for (int i = 0; i < v; i++)
    {
        dist[i]=INT_MAX;
    }
    dist[s]=0;
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                dist[v]=dist[u]+1;
                visited[v]=true;
                q.push(v);
            }                          
        }
    }
    // print
    // cout<<"\nShortest path from source "<<s<<" is: ";
    for (int i = 0; i < v; i++)
    {
        cout<<dist[i]<<" ";                                                     
    }               
    
    
    
}
// TUF method
void BFS_shortest_dist(int src,vector<int> adj[], int V)
{

    // initializing distance array with infinity distance
    vector<int> dist(V, INT_MAX);
    queue<int> q;   // create queue
    q.push(src);    // push source into queue
    dist[src] = 0;  // update source distance 0
    // start BFS while queue is not empty
    while(!q.empty())
    {   // takeout an node and delete from queue
        int node = q.front();
        q.pop();
        // traverse through its adjacent nodes
        for(auto it: adj[node]){
            // if node distance +1 is smaller than adjacent node's distance 
            // then update adjacent node's distance
            // and push that node in to queue
            if(dist[node]+1 < dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }

        }
    }
    // print distance from source
    for (int i = 0; i < V; i++)
    {
        cout<<dist[i]<<" ";
    }
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
    int v=4;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    // printGraph(adj,v);
    int src=0; // source
    cout<<"\nShortest path from source "<<src<<" is: ";
    shortestPath(adj,src,v);
    cout<<"\nShortest path from source "<<src<<" is: ";
    BFS_shortest_dist(src, adj, v);
    return 0;
}