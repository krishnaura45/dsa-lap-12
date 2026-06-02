// Depth First Search in a graph --> Traversal Technique
// Implementation -> Recursion
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V+1] = {0}; 
        int start = 3;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfs(start, adj, vis, ls); 
        return ls; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> adj[n+1];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u;
        cin>>v;
        addEdge(adj,u,v);
    }

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(n, adj);
    printAns(ans);

    return 0;
}