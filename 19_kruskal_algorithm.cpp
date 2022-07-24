// code not complete
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

bool comp(node a, node b){
    return (a.wt < b.wt);
}

int findpar(int u, vector<int> &parent)
{
    if(u==parent[u]) return u;
    else
        return parent[u]=findpar(parent[u],parent);


}

void unionn(int u, int v,vector<int> &parent, vector<int> &rank)
{
    u=findpar(u,parent);
    v=findpar(v,parent);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int main(){
    
    int N=5,m=6;
	vector<node> edges; 
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(N);
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }
    int cost = 0;
	vector<pair<int,int> > mst; 
    vector<int> rank(N, 0);
	for(auto it : edges) {
	    if(findpar(it.v, parent) != findpar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
    cout<<cost<<endl;
    for(auto it:mst){
        cout<<it.first<<" - "<<it.second<<endl;
    }
    return 0;
}