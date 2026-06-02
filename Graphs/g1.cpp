// Graph representation in C++
#include<bits/stdc++.h>
using namespace std;

// For undirected graphs
// Adjacency matrix
void adj_matrix(int n,int m){
    // time complexity: O(n)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // this statement will be removed in case of directed graph
    }
    cout<<"Matrix formed";
}

// Adjacency List
void adj_list(int n,int m){
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"List formed";
}

int main(){
    int n, m;
    cin >> n >> m;
    adj_matrix(n,m);
    adj_list(n,m);
    return 0;
}
