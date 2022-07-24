#include<bits/stdc++.h>
using namespace std;
#define v 6		//No of vertices


void floyd_warshall(int graph[v][v])
{
    int dist[v][v];
    // Assign all values of graph to allpairs shortest distance
    // copy the data to distance matrix
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            dist[i][j] = graph[i][j];
        }
    }

    // Find all pair shortest path by trying all possible paths
    for (int k = 0; k < v; k++) // try for all intermediate node
        for(int i=0; i<v; i++)  
            for (int j = 0; j < v; j++)
            {
                // [skip if k is unreachable from i] OR [j is unreachable from k] 
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) 
                    continue;
                // check is new distance through k vertex is shorter than update distance
                else if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
            
    // Check if graph has negative edge cycle
    for(int i=0; i<v; i++){
        if(dist[i][i] < 0){
            cout<<"Negative edge weight cycle is present\n";
            return;
        }
    }

    // print shortest path graph
    for (int i = 0; i < v; i++){
        for(int j=0; j<v; j++){
            cout<<i<<" to "<<j<<" distance is "<<dist[i][j]<<endl;
        }
    }
        cout<<"*************************"<<endl;
}

int main(){
 
    int graph[v][v] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
						{INT_MAX, 0, 4, 2, 7, INT_MAX},
						{INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
						{INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };
    
	floyd_warshall(graph);
    return 0;
}