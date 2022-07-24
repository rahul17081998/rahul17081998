#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight){
        u=first;
        v=second;
        wt=weight;
    }
};

int main(){

    int N=6;    // No of nodes
    int m=7;    // No of edges
    vector<node> edges;
    edges.push_back(node(0,1,5));
    edges.push_back(node(1,2,-2));
    edges.push_back(node(1,5,-3));
    edges.push_back(node(2,4,3));
    edges.push_back(node(3,2,6));
    edges.push_back(node(3,4,-2));
    edges.push_back(node(5,3,1));

    int src=0;  // source 
    int inf=1000000;
    vector<int> dist(N,inf);    // Declared a disteance array with infinity
    dist[src]=0;    // distance to source 
    
    // Relax the edges
    // iterate N-1 times bcz we have to relax the edges that many times
    for(int i=1; i<=N-1; i++){      
        for(auto it:edges){
            if(dist[it.u]+it.wt<dist[it.v]){    // relaxing edges
                dist[it.v]=dist[it.u]+it.wt;
            }
        }
    }
    // one more relaxation to all the edges to find that 
    // if distance of v is greater than u that means there is a negative edge cycle
    // if negative edge cycle found than bellman ford algorithm can not sove this problem 
    // but it will give a message to the programmer that there a negative edge cycle 
    // so i am not able to solve this problem.
    
    int f1=0;
    for(auto it:edges){
        if(dist[it.u]+it.wt<dist[it.v]){    // if this is satisfyed --> negative cycle detected
            cout<<"Negative cycle.";
            f1=1;
            break;
        }
    }

    // if the counter not been set(1) then
    // i have shortest diatance source to every node
    if(!f1){  
        for(int i = 0; i<N; i++){
            cout<<dist[i]<<" ";
        }
    }
    return 0;
}