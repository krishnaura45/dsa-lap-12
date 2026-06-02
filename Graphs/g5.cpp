// P2 -> Number of Islands OR
// Number of connected components

// 1 represents land and 0 represents water in the grid
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    // bfs modified 
    void bfs(int row,int col,vector<vector<char>> grid, vector<vector<int>> &vis) {
        
    }
  public:
    int numIslands(vector<vector<char>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};

int main() {
    
    vector<vector<int>> grid
    {
        {'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '0'},
        {'1', '1', '0', '1'}
    };

        
    Solution ob;
    cout << ob.numIslands(grid) << endl;
        
    return 0;
}