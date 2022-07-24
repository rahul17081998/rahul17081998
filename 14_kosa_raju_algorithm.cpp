
// We have given directed graph 
// we need to find al the strongly connected component(SCC) in it 
// and we need to print SCC seprated by new line
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,st,vis,adj);
        }
    }
    st.push(node);
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]){
    cout<<node<<" ";
    vis[node]=1;
    for(auto it:transpose[node]){
        if(!vis[it]){
            revDfs(it,vis,transpose);
        }
    }
}

int main()
{
    int n,m;
    cin>> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>> u >> v;
        adj[u].push_back(v);
    }
    // step1: sort all the node in finishing time order
    stack<int> st;
    vector<int> vis(n,0);
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            dfs(i,st,vis,adj);
        }
    }
    // step2: transpose of the graph, so that you dont endup going to the other part
    vector<int> transpose[n];

    for(int i=0; i<n; i++){
        vis[i]=0;
        for(auto it:adj[i]){
            transpose[it].push_back(i);
        }
    }
    // Do dfs according to the finishing time
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            cout<<"SCC: ";
            revDfs(node,vis,transpose);
            cout<<endl;
        }
    }

    return 0;

}

/*
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}
int main() {
    int n=6, m=7;
	vector<int> adj[n+1]; 
	adj[1].push_back(3);
	adj[2].push_back(1);
	adj[3].push_back(2);
	adj[3].push_back(5);
	adj[4].push_back(6);
	adj[5].push_back(4);
	adj[6].push_back(5);
	
	stack<int> st;
	vector<int> vis(n+1, 0); 
	for(int i = 1;i<=n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	vector<int> transpose[n+1]; 
	
	for(int i = 1;i<=n;i++) {
	    vis[i] = 0; 
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); 
	    }
	}
	
	
	
	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
	
	
	return 0;
}
*/