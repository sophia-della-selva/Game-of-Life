
#include <iostream>

// functon to create rows
bool rows(int board[9][9], int num, int col, int row) {

  for (int i = 0; i < 9; i++) {
    if (board[row][i] == num) {
      if (i != col) {
        return false;
      }
    }
  }

  return true;
}

// function to create columns
bool cols(int board[9][9], int num, int row, int col) {

  for (int i; i < 9; i++) {
    if (board[i][col] == num) {
      if (i != row) {
        return false;
      }
    }
  }

  return true;
}

// function to create box
bool box(int board[9][9], int row, int col) {

  for (int num = 1; num <= 9; num++) {

    int counter = 0;

    for (int i = row; i < row + 3; i++) {
      for (int j = col; j < col + 3; j++) {
        if (board[i][j] == num) {
          counter++;
        }
      }
    }

    if (counter > 1) {
      return false;
    }
  }

  return true;
}

// main
int main() {

  // create the board
  int board[9][9];

  bool correct = true;

  // loop through board and get inputs
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      std::cin >> board[i][j];
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (rows(board, board[i][j], j, i) == false) {
        correct = false;
      }

      if (cols(board, board[i][j], i, j) == false) {
        correct = false;
      }

      if (i % 3 == 0 && j % 3 == 0) {
        if (box(board, i, j) == false) {
          correct = false;
        }
      }
    }
  }

  // output
  if (correct == true) {
    std::cout << "Solution is good!";
  }

  else if (correct == false) {
    std::cout << "Wrong solution!";
  }

  return 0;
}