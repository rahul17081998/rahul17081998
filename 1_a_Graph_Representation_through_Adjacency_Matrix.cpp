#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
    bool **adjMatrix;
    int numVertices;

    public:
    Graph(int numVertices)
    {
        this->numVertices=numVertices;
        adjMatrix = new bool *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new bool[numVertices];
            for(int j=0; j<numVertices; j++)
                adjMatrix[i][j] = false;
        }
        
    }

    // Add an edge
    void addEdge(int i, int j)
    {
        adjMatrix[i][j]=true;
        adjMatrix[j][i]=true;
    }
    // Remove an edge
    void removeEdge(int i, int j)
    {
        adjMatrix[i][j]=false;
        adjMatrix[j][i]=false;
    }
    // print matrix
    void printAdjMat()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout<<i<<" : ";
            for (int j = 0; j < numVertices; j++)
            {
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
            
        }
    }
};
int main(){
    Graph g(4);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(0,2);
    g.addEdge(1,0);
    g.addEdge(2,1);
    // print adjacency matrix
    g.printAdjMat();
    g.removeEdge(1,3);
    cout<<endl;
    g.printAdjMat();
    return 0;
}