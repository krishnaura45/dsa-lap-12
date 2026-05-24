// Sudoku Solver
#include<bits/stdc++.h>
using namespace std;

// Function to check if a move is valid at a given position
bool isValid(vector<vector<char>> &board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    // Check the row for the same character 'c'
    if (board[i][col] == c)
      return false;

    // Check the column for the same character 'c'
    if (board[row][i] == c)
      return false;

    // Check the 3x3 subgrid for the same character 'c'
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

// Recursive function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<char>> &board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            // Place a valid character 'c' in the cell
            board[i][j] = c;

            // Recursively try to solve the puzzle with this move
            if (solveSudoku(board))
              return true;
            else
              board[i][j] = '.'; // If it doesn't lead to a solution, backtrack
          }
        }

        return false; // If no valid character can be placed, backtrack further
      }
    }
  }
  return true; // The puzzle is solved
}

int main() {
  // Initialize the Sudoku board
  vector<vector<char>> board{
      {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
      {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
      {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
      {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
      {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
      {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
      {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
      {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
      {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

  // Call the Sudoku solver function
  solveSudoku(board);

  // Print the solved Sudoku board
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++)
      cout << board[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
