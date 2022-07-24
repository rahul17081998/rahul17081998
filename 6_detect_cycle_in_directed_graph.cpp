#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Add an edge in graph using list 
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}
// Detect cycle in directed graph
bool DFSRec(vector<int>adj[],int s,bool visited[],bool recSt[])
{
    visited[s]=true;
    recSt[s]=true;
    for(int u:adj[s])
    {
        if(visited[u]==false && DFSRec(adj,u,visited,recSt))
            return true;
        else if(recSt[u]==true)
            return true;
    }
    recSt[s]=false;
    return false;
}
bool isCycle(vector<int> adj[],int v)
{
    bool visited[v];
    bool recSt[v];
    for (int i = 0; i < v; i++)
    {
        visited[i]=true;
        recSt[i]=true;
        for (int i = 0; i < v; i++)
        {
            if(visited[i]==false)
            {
                if(DFSRec(adj,i,visited,recSt)==true)
                    return true;
            }
        }
        
    }
    return false;
    
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
    int v=6;
    vector<int> adj[v];
    
    addEdge(adj,0,1);
    addEdge(adj,2,1);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,3);
    printGraph(adj,v);
   
    cout<<"\nIs cycle detected: "<<isCycle(adj,v)<<endl;
    
    return 0;
}