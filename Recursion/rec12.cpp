// Alternative for loop instead of while
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Check if it's safe to place a queen in the current row and column
    bool isSafe(int row, int col, vector<string> board, int n) {
    
      // Check upper diagonal elements
      int r=row;
      int c=col;
      for(c=col;c>=0 && r>=0;c--,r--){
        if(board[r][c]=='Q') 
         return false;
      }

      // Check left horizontal elements  <---
      for(c=col;c>=0;c--){
        if(board[row][c]=='Q') 
         return false;
      }

      // Check lower diagonal elements
      r=row;
      for(c=col;c>=0 && r<=n-1;c--,r++){
        if(board[r][c]=='Q') 
         return false;
      }

      // If no queen is attacking the current position, return true (it's safe)
      return true;
    }

  public:
    // Recursive function to solve the N-Queens problem
    void solve(int col,int n,vector<string> &board,vector<vector<string>> &ans) {
      // If all queens are placed, add the current board configuration to the answer
      if (col == n) {
        ans.push_back(board);
        return;
      }
      // Try placing a queen in each row of the current column
      for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
          // Place a queen and recursively solve for the next column
          board[row][col] = 'Q';
          solve(col + 1,n,board,ans);

          // Backtrack by removing the queen to explore other possibilities
          board[row][col] = '.';
        }
      }
    }

  public:
    // Function to solve the N-Queens problem and return all valid solutions
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);  
      // This line declares a vector called board that will hold n strings. Each string represents a row of the chessboard. So, board effectively represents an n x n chessboard.

      string s(n, '.');  
      // This line creates a string s consisting of n dots ('.'). This string s represents an empty row on the chessboard, where each '.' represents an empty cell.

      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      // In each iteration, it assigns the string s (which is an empty row) to the i-th row of the chessboard represented by the board vector. This effectively initializes the entire chessboard to have n empty rows, where each row is represented by the string s.

      // Start solving from the first column (column 0)
      solve(0,n,board,ans);
      return ans;
    }
};

int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}