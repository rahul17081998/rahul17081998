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

bool bipartiteBFS(int src, vector<int> adj[], int colour[])
{
    // initially create a queue ds and push the source node
    // and enable the colour of source node with any of two colour[1/0].
    queue<int> q;
    q.push(src);
    colour[src] = 1;
    // start BFS
    while(!q.empty()){
        // take out an element from queue and pop it 
        int node = q.front();
        q.pop();
        // traversing it's adjacent node
        for(auto it: adj[node]){
            // while traversing if its colour of adjacent node is -1
            // it give's you an idea that it is not colored
            if(colour[it] == -1){
                // give adjacent node's to opposite colour than node colour
                colour[it] = 1-colour[node];
                q.push(it); // push into 
            }
            // if adjacent node is already coloured
            // then check adjacent node's colour with node
            // if it is same colour than it is not a bipartite graph
            else if(colour[it] == colour[node])
                return false;
        }
    }
    return true;
}
// check wether given graph is bipartite or not
bool isBipartite(int V, vector<int>adj[]){
    // decleared a coloured array of V size
    int colour[V];
    // and it is initialized with -1
    memset(colour, -1, sizeof colour);
    
    // iterating for all the node 
    // if graph have multiple components
    for(int i=0; i<V; i++){
        // if a node is not visited 
        if(colour[i]==-1){
            // if your graph have multiple component and 
            // if any of the component have is not bipatite the your
            // graph is not a bipartite
            if(bipartiteBFS(i, adj, colour)==false)
                return false;
        }
    } 
    return true;
}



int main(){
    int V=9;
    vector<int> adj[V];
    // cycle is present for below input
    addEdge(adj,8,7);
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,6);
    addEdge(adj,6,7);
    addEdge(adj,1,7);
    addEdge(adj,4,5);
   
    cout<<"\nIs Graph is bipartite: "<<isBipartite(V, adj)<<endl;
    
    return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/

