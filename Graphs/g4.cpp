// PROBLEMS ON BFS/DFS
// P1 -> Number of provinces
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj[],int vis[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}

int findNumProvinces(vector<vector<int>> &isConnected){
    int v=isConnected.size();
    vector<int> adj[v+1];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int cnt=0;
    int vis[v+1]={0};
    for(int i=1;i<=v;i++){
        if(vis[i]==0){
            cnt++;
            dfs(i,adj,vis);
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> adjmatrix={{1,0,0},{0,1,0},{0,0,1}};
    int ans=findNumProvinces(adjmatrix);
    cout<<ans;
    return 0;
}