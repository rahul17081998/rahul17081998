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
// DFS for disconnected graph
void DFSrec(vector<int> adj[],int s,bool visited[])
{
    visited[s]=true;
    // cout<<s<<" ";
    for(int u:adj[s])
    {
        if(visited[u]==false)
        {
            DFSrec(adj,u,visited);
        }
    }
}
int DFS(vector<int> adj[], int v, int s)
{
    bool visited[v+1];
    int count=0;
    for (int i = 0; i < v; i++) {visited[i]=false;}
    for (int i = 0; i < v; i++)
    {
        if(visited[i]==false)
        {
            count++;    
            DFSrec(adj,i,visited);
        }
    }  
    return count;
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
    int v=2;
    vector<int> adj[v];
    
    addEdge(adj,0,0);
    addEdge(adj,1,1);
    // addEdge(adj,1,2);
    // addEdge(adj,1,3);
    // addEdge(adj,2,3);
    // addEdge(adj,4,5);
    // addEdge(adj,4,6);
    // addEdge(adj,5,6);
    //
    // printGraph(adj,v);
    int s=1; // source
    // cout<<endl;
    cout<<"\n No of iland in graph--> "<<DFS(adj,v,s)<<endl;
    return 0;
}