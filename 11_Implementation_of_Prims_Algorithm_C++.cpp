#include<bits/stdc++.h>
using namespace std;
#define V 4

// prism algorihm
int primMST(int graph[V][V])
{
    int key[V];
    int res=0;
    fill(key,key+V,INT_MAX);
    key[0]=0;
    bool mSet[V];
    for (int i = 0; i < V; i++)
    {
        mSet[i]=false;
    }
    for (int count = 0; count < V; count++)
    {
        int u=-1;
        for (int i = 0; i < V; i++)
        {
            if(!mSet[i] && (u==-1 || key[i]<key[u]))
                u=i;
        }
        mSet[u]=true;
        res=res+key[u];
        for (int v = 0; v < V; v++)
        {
            if(graph[u][v]!=0 && !mSet[v])
                key[v]=min(key[v],graph[u][v]);
        }
    }
    return res;
}


int main(){
    int graph[V][V] = { { 0, 5, 8, 0}, 
						{ 5, 0, 10, 15 }, 
						{ 8, 10, 0, 20 }, 
						{ 0, 15, 20, 0 },}; 

	cout<<primMST(graph); 
    
    return 0;
}