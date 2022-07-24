// C++ program to find articulation points in an undirected graph

#include<bits/stdc++.h>
using namespace std;
// A recursive function that find articulation
// points using DFS traversal
// adj[] --> Adjacency List representation of the graph
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
// discovery time) that can be reached from subtree
// rooted with current vertex
// parent --> Stores the parent vertex in DFS tree
// isAP[] --> Stores articulation points
void APUtil(vector<int> adj[], int u, bool visited[], int disc[], 
                int low[], int &time, int parent, bool isAP[])
    {
        int children=0;
        // mark the current node visited
        visited[u]=true;
        // initialize discovery and low time
        low[u]=disc[u]=++time;
        // Go through all the vertices adjacent to it
        for(auto v:adj[u]){
            // if v is not visited yet then mark it as a chield
            // DFS tree recure it
            if(!visited[v]){
                children++;
                APUtil(adj,v,visited,disc,low,time,u,isAP);
                // check if subtree rooted with v has a
                // connection to one of the ancestores of u
                low[u]=min(low[u],low[v]);
                // if u is not root/parent and low valuews of one of its chield is more than discovery value of u
                if(parent!=-1 && low[v] >= disc[u]){
                    isAP[u] = true;
                }
            }
            // update low value of u for parent calls.
            else if(v!=parent){
                low[u]=min(low[u],disc[v]);
            }
        }
        // if u is root of DFS and has two or more children.
        if(parent == -1 && children >1)
            isAP[u]=true;
    }

void AP(vector<int> adj[],int V)
{
    int disc[V];
    int low[V];
    bool visited[V];
    bool isAP[V];
    int time =0;
    int par=-1;

    for (int i = 0; i < V; i++)
    {
        disc[i]=0;
        visited[i]=false;
        isAP[i]=false;
    }
    // code works even if we give disconneted graph
    for(int u=0; u<V; u++)
    {
        if(!visited[u])
        {
            APUtil(adj,u,visited,disc,low,time,par,isAP);

        }
    }
    // print the Articulation Points 
    for(int u=0; u<V; u++)
    {
        if(isAP[u] == true)
            cout<<u<<" ";
    }

}
// utility function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    // create 1st graphs and find articulation points
    int V=5;
    cout << "Articulation points in 1st graph \n";
    vector<int> adj1[V];
    addEdge(adj1,1,0);
    addEdge(adj1,0,2);
    addEdge(adj1,2,1);
    addEdge(adj1,0,3);
    addEdge(adj1,3,4);
    AP(adj1, V);

    // create 2nd graphs and find articulation points
    
    cout << "\nArticulation points in 2nd graph \n";
    V = 7;
    vector<int> adj3[V];
    addEdge(adj3, 0, 1);
    addEdge(adj3, 1, 2);
    addEdge(adj3, 2, 0);
    addEdge(adj3, 1, 3);
    addEdge(adj3, 1, 4);
    addEdge(adj3, 1, 6);
    addEdge(adj3, 3, 5);
    addEdge(adj3, 4, 5);
    AP(adj3, V);
    return 0;
}