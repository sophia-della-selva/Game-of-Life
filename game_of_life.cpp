#include <iostream>
#include <vector>

int neighbor(std::vector<std::vector<char>> &grid, int row, int col, int x,
             int y) {

  int counter;

  counter = 0;

  // top left
  if (x - 1 >= 0) {
    if (y - 1 >= 0) {
      if (grid[x - 1][y - 1] == '*') {
        counter++;
      }
    }
  }

  // top middle
  if (x - 1 >= 0) {
    if (grid[x - 1][y] == '*') {
      counter++;
    }
  }

  // top right
  if (x - 1 >= 0) {
    if (y + 1 < col) {
      if (grid[x - 1][y + 1] == '*') {
        counter++;
      }
    }
  }

  // bottom left
  if (x + 1 < row) {
    if (y - 1 >= 0) {
      if (grid[x + 1][y - 1] == '*') {
        counter++;
      }
    }
  }

  // bottom middle
  if (x + 1 < row) {
    if (grid[x + 1][y] == '*') {
      counter++;
    }
  }

  // bottom right
  if (x + 1 < row) {
    if (y + 1 < col) {
      if (grid[x + 1][y + 1] == '*') {
        counter++;
      }
    }
  }

  // actual left
  if (y - 1 >= 0) {
    if (grid[x][y - 1] == '*') {
      counter++;
    }
  }

  // actual right
  if (y + 1 < col) {
    if (grid[x][y + 1] == '*') {
      counter++;
    }
  }

  return counter;
}

int main() {

  int m, n, g;

  std::cin >> m;

  std::cin >> n;

  std::cin >> g;

  std::vector<std::vector<char>> grid(m, std::vector<char>(n));
  std::vector<std::vector<char>> grid2(m, std::vector<char>(n));

  // grid 1
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> grid[i][j];
    }
  }

  // running generations
  for (int num = 0; num < g; num++) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int counter = neighbor(grid, m, n, i, j);
        {
          if (grid[i][j] == '*') {
            if (counter < 2 || counter > 3) {
              grid2[i][j] = '.';
            } else {
              grid2[i][j] = '*';
            }
          } else {
            if (counter == 3) {
              grid2[i][j] = '*';
            } else {
              grid2[i][j] = '.';
            }
          }
        }
      }
    }

    grid = grid2;
  }

  // output
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << grid[i][j];
      if (j != n - 1) {
        std::cout << ' ';
      }
    }
    std::cout << '\n';
  }

  return 0;
}