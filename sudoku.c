/*
Authors:
Wilton Rodrigues - 13/0049212 - GG
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sum of numbers, spaces, \n and \0
#define LINE_SIZE 19
// Default grid size
#define GRID_SIZE 9
#define EMPTY 0

// Define a type to get data from input
typedef struct char_grid_t{
  char position[GRID_SIZE][LINE_SIZE];
} char_grid_t;

// Define a type to put the cleaned data
typedef struct int_grid_t{
  int position[GRID_SIZE][GRID_SIZE];
} int_grid_t;

// Read input from stdin and allocate to char matrix
char_grid_t read_grid(){
  char buffer[LINE_SIZE];
  int i;
  char_grid_t char_grid;

  for (i = 0; i < GRID_SIZE; ++i) {
    fgets(buffer, sizeof(buffer), stdin);
    strcpy(char_grid.position[i], buffer);
    // Add \0 for last line element
    char_grid.position[i][LINE_SIZE - 1] = '\0';
  }

  return char_grid;
}

// Convert the char elements to int and allocate to int matrix
int_grid_t convert_grid_to_int(char_grid_t char_grid){
  int_grid_t int_grid;
  int i, j;

  for (i = 0; i < GRID_SIZE; ++i) {
    for (j = 0; j < LINE_SIZE; j+=2) {
      // If the element is anything different of a number put 0 in there
      if(char_grid.position[i][j] < '1' || char_grid.position[i][j] > '9')
        int_grid.position[i][j/2] = EMPTY;
      else
        int_grid.position[i][j/2] = char_grid.position[i][j] - '0';
    }
  }

  return int_grid;
}

// Function to print the grid
void print_grid(int_grid_t int_grid){
  int i, j, is_pipe;

  for (i = 0; i < GRID_SIZE; ++i) {
    for (j = 0; j < GRID_SIZE; ++j) {
      /* printf("%2d", int_grid.position[i][j]); */
      if(j == 8)
        is_pipe = j % 3;
      else
        is_pipe = (j + 1) % 3;
      printf((is_pipe == 0) ? "%d | " : (j == 8) ? "%d" : "%d ", int_grid.position[i][j]);
    }
    if(i == 8)
      is_pipe = i % 3;
    else
      is_pipe = (i + 1) % 3;
    printf((is_pipe == 0) ? "\n- - - - - - - - - - -\n" : "\r\n");
  }
}

// Check if the passed element exist in passed row
int used_in_row(int_grid_t grid, int row, int number){
  int i;
  for (i = 0; i < GRID_SIZE; ++i){
    if (grid.position[row][i] == number)
      return 1;
  }
  return 0;
}

// Check if the passed element exist in passed column
int used_in_col(int_grid_t grid, int col, int number){
  int i;
  for (i = 0; i < GRID_SIZE; ++i){
    if (grid.position[i][col] == number)
      return 1;
  }
  return 0;
}

// Check if the passed element exist in passed box
int used_in_box(int_grid_t grid, int i_row, int i_col, int number){
  int i, j;
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j){
      if (grid.position[i + i_row][j + i_col] == number)
        return 1;
    }
  return 0;
}

int is_safe(int_grid_t grid, int row, int col, int number){
  if (!used_in_row(grid, row, number) &&
      !used_in_col(grid, col, number) &&
      !used_in_box(grid, row - row % 3 , col - col % 3, number))
    return 1;
  else
    return 0;
}

int main(int argc, char *argv[]){
  /* int i, j; */

  char_grid_t temp_char_grid = read_grid();
  int_grid_t sudoku = convert_grid_to_int(temp_char_grid);
  print_grid(sudoku);

  return 0;
}
