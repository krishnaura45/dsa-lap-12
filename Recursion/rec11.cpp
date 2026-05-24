// N Queen Problem --> Hard (Recursion and Backtracking)
// Problem Statement: The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen’s placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.

// APPROACH 1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Check if it's safe to place a queen in the current row and column
    bool isSafe(int row, int col, vector<string> board, int n) {
      int duprow = row;
      int dupcol = col;

      // Check upper diagonal elements
      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;   // check till zero row and column
      }

      // Check left horizontal elements  <---
      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;   // check till zero column
      }

      // Check lower diagonal elements
      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;    // check till zero column and n-1 row
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
