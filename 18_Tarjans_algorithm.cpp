// C++ program to find Strongly Connected Component (SCC) in an undirected graph

#include<bits/stdc++.h>
#define NIL -1
using namespace std;
// A recursive function that finds and prints strongly connected
// components using DFS traversal
// u --> The vertex to be visited next
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
//             discovery time) that can be reached from subtree
//             rooted with current vertex
// *st -- >> To store all the connected ancestors (could be part
//         of SCC)
// stackMember[] --> bit/index array for faster check whether
//                 a node is in stack

void dfsRec(vector<int> adj[],int u, int disc[], int low[], stack<int> *st, bool stackMember[])
/*
{
    static int time=0;
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u]=true;
    for(auto v: adj[u]){
        // int v=i;
        if(disc[v] == -1){
            dfsRec(adj,v,disc,low,st,stackMember);
            low[u]=min(low[u],low[v]);
        }
        else if(stackMember[v] == true){
            low[u]=min(low[u],disc[v]);
        }
    }

    int w=0;
    if(low[u]==disc[u]){
        while(st->top()!=u){
            w = (int) st->top();
            cout<< w << "\n";
            stackMember[w]=false;
            st->pop();
        }
        w = (int) st->top();
        cout<< w << "\n";
        stackMember[w] = false;
        st->pop();
    }
}
*/
{
    // A static variable is used for simplicity, we can avoid use
    // of static variable by passing a pointer.
    static int time = 0;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;
 
    // Go through all vertices adjacent to this
    // list<int>::iterator i;
    for (auto v:adj[u])
    {
        // int v = *i; // v is current adjacent of 'u'
 
        // If v is not visited yet, then recur for it
        if (disc[v] == -1)
        {
            dfsRec(adj,v, disc, low, st, stackMember);
 
            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 (per above discussion on Disc and Low value)
            low[u] = min(low[u], low[v]);
        }
 
        // Update low value of 'u' only of 'v' is still in stack
        // (i.e. it's a back edge, not cross edge).
        // Case 2 (per above discussion on Disc and Low value)
        else if (stackMember[v] == true)
            low[u] = min(low[u], disc[v]);
    }
 
    // head node found, pop the stack and print an SCC
    int w = 0; // To store stack extracted vertices
    if (low[u] == disc[u])
    {
        while (st->top() != u)
        {
            w = (int) st->top();
            cout << w << " ";
            stackMember[w] = false;
            st->pop();
        }
        w = (int) st->top();
        cout << w << "\n";
        stackMember[w] = false;
        st->pop();
    }
}
void scc(vector<int> adj[],int V){
    /*
    int disc[V];
    int low[V];
    // int time =0;
    bool stackMember[V];
    stack<int> *st = new stack<int>();
 

    for(int i=0; i<V; i++){
        disc[i]=-1;
        low[i]=-1;
        stackMember[i]=false;
    }

    for(int i=0; i<V; i++){
        if(disc[i]==-1){
            dfsRec(adj,i,disc,low,st,stackMember);
        }
    }
    */
   int *disc = new int[V];
    int *low = new int[V];
    bool *stackMember = new bool[V];
    stack<int> *st = new stack<int>();
 
    // Initialize disc and low, and stackMember arrays
    for (int i = 0; i < V; i++)
    {
        disc[i] = NIL;
        low[i] = NIL;
        stackMember[i] = false;
    }
 
    // Call the recursive helper function to find strongly
    // connected components in DFS tree with vertex 'i'
    for (int i = 0; i < V; i++)
        if (disc[i] == NIL)
            dfsRec(adj,i, disc, low, st, stackMember);

}
// utility function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}
int main(){
    // create 1st graphs and find articulation points
    int V=5;
    cout << "SCC in 1st graph \n";
    vector<int> adj1[V];
    addEdge(adj1,1,0);
    addEdge(adj1,0,2);
    addEdge(adj1,2,1);
    addEdge(adj1,0,3);
    addEdge(adj1,3,4);
    scc(adj1, V);

    // create 2nd graphs and find articulation points
    cout << "\nSCC in 2nd graph \n";
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
    scc(adj1, V);
   
    return 0;
}