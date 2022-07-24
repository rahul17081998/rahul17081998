#include<bits/stdc++.h>
using namespace std;
#define V 4

// Dijkstra Algorithm
// time complexity = O(V^2);
vector<int> dijkstra(int graph[V][V], int src)
{
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    vector<bool> fin(V,false);
    for(int count=0; count<V-1; count++)
    {
        // Pick the minimum vertex distance which is not finialized
        int u=-1;   
        for (int i = 0; i < V; i++)
        {
            if(!fin[i] && (u==-1 || dist[i]<dist[u]))
                u=i;
        }

        fin[u]=true;

        for (int v = 0; v < V; v++)
        {
            if(graph[u][v]!=0 && fin[v]==false)
                dist[v]=min(dist[v],dist[u]+graph[u][v]);
        }
        
    }
    return dist;
}
// this program is right 
// after doing some modification it will run (it execued sucessfully in GFG practice)
// taken from GFG practice
// Dijkstra Algorithm using priority queue
/*
vector <int> dijkstraUsingPQ(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    // pair: first--->distance, second--->vertex
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    // insert source itself into priority queue and initialize its distance 0
    pq.push(make_pair(0, S));
    // create a distance vector and initialize distance from source to all node infinity
    vector<int> dist(V, INT_MAX);
    dist[S] = 0; // source to source distance is 0
    
    while(pq.empty()==false)
    {
        int u = pq.top().second;    
        pq.pop();
        
        for(auto it: adj[u]){
            int v = it[0];
            int weight = it[1];
            if(dist[v] > dist[u]+weight){
                dist[v] = dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    
    return dist;
}
*/

int main(){

    int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },};  

	int src=0;
    // dijkstra(graph,src) return a vector
    vector<int> v = dijkstra(graph,0);

    for(int x:v)
    {
        cout<<x<<" ";
    }
    return 0;
}