// Breadth First Search in a graph --> Traversal Technique
// Level order traversal
// Implementation -> queue
#include<bits/stdc++.h>
using namespace std;

// n --> nodes/vertices, adj[] --> adjacency list
vector<int> bfs(int n,vector<int> adj[],int start_node){
    int vis[n+1]={0};
    vis[start_node]=1;

    queue<int> q;         // FIFO
    q.push(start_node);            // push the initial starting node 
    
    vector<int> bfs; 
    
    while(!q.empty()) {   // iterate till the queue is empty 
        
        int node = q.front();      // get the frontmost element in the queue 
        q.pop();                   // remove the node
        bfs.push_back(node);       // add in traversal list
        
        for(auto it : adj[node]) { // traverse for all its neighbours 
            // if the neighbour has previously not been visited, store in Q and mark as visited 
            if(!vis[it]) {
                vis[it] = 1; 
                q.push(it); 
            }
        }
    }
    return bfs;
}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
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

    int start=6;
    vector<int> ans=bfs(n,adj,start);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}