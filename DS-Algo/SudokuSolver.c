// Recursive sudoku solver that uses backtracking

#include <stdio.h>
#include <stdbool.h>

// x refers to rows , i 
// y refers to cols , j

void display(int grid[9][9]) {
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

void print_bool(bool val) {
  printf(val ? "true\n" : "false\n");
}

bool row_match_ok(int grid[9][9], int num, int x) {
  // Checks if num is present in row or not
  for(int j=0; j<9; j++) {
    if(num == grid[x][j]) {
      return false;
    }
  }
  return true;
}

bool col_match_ok(int grid[9][9], int num, int y) {
  // Checks if num is present in column or not
  for(int i=0; i<9; i++) {
    if(num == grid[i][y]) {
      return false;
    }
  }
  return true;
}

bool box_match_ok(int grid[9][9], int num, int x, int y) {
  // Stores the coords of the first element of respective box
  int i_begin = ((int) x / 3) * 3;
  int j_begin = ((int) y / 3) * 3;

  for(int i= i_begin; i < i_begin+3; i++) {
    for(int j = j_begin; j < j_begin+3; j++) {
      if(grid[i][j] == num)
        return false;
    }
  }
  return true;
}

bool isOk(int grid[9][9], int num, int x, int y) {
  return row_match_ok(grid, num, x) && 
         col_match_ok(grid, num, y) && 
         box_match_ok(grid, num, x, y);
}

bool sudoku_solver(int grid[9][9], int x, int y)
{
    // We are at the end of the sudoku
    if (x == 8 && y == 9)
        return true;

    // If at the end of a col, move y to the beginning of the next row
    if (y == 9)
    {
        x++;
        y = 0;
    }

    // If box is not empty move to the next box
    if (grid[x][y] != 0)
        return sudoku_solver(grid, x, y+1);
  
    // Loop 1-9 and check if 'n' works
    for (int n = 1; n < 10; n++)
    {
        if (isOk(grid, n, x, y))
        {   
            // Set that box to 'n'
            grid[x][y] = n;
            // Checking if next box is solvable
            if (sudoku_solver(grid, x, y+1))
                return true;
        }
        // The next boxes are not solvable, so make this one empty and try with n+1
        grid[x][y] = 0;
    }
    return false;
}


int main() {
  int grid[9][9] = 
      {  {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };

  display(grid);
  sudoku_solver(grid, 0, 0);
  printf("\nSolved: \n");
  display(grid);
  return 0;
}
