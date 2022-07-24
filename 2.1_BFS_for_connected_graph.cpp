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
// BFS
void BFS(vector<int> adj[],int v,int s)
{
    bool visited[v+1];
    for (int i = 0; i < v; i++)
    {
        visited[i]=false;
    }
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for (int i:adj[u])
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                q.push(i);
            }
        }
        
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
    addEdge(adj,2,3);
    printGraph(adj,v);
    int s=3; // source
    cout<<"source vertex "<<s<<" visites: ";
    BFS(adj,v,s);
    return 0;
}