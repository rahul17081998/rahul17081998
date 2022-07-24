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
void BFS(vector<int> adj[],int s,bool visited[])
{
    
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        // cout<<u<<" ";
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
// BFS for disconnected graph 
int BFSDis(vector<int> adj[],int v)
{
   bool visited[v+1];
   int count=0;
   for (int i = 0; i < v; i++)
   {
       if(visited[i]==false)
       {
           BFS(adj,i,visited);
           count++;
       }
   }
   return count;
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
    int v=7;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    // addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    addEdge(adj,4,6);
    addEdge(adj,5,6);
    /*
    cout<<"print adjacency list\n";
    printGraph(adj,v);
    */
    cout<<"\nNo if island--> "<<BFSDis(adj,v)<<endl;
    
    return 0;
}