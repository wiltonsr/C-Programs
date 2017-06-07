#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 18
#define GRID_SIZE 9
#define EMPTY 0

typedef struct char_grid_t{
  char grid[GRID_SIZE][LINE_SIZE];
} char_grid_t;

typedef struct int_grid_t{
  int grid[GRID_SIZE][GRID_SIZE];
} int_grid_t;

char_grid_t read_grid(){
  char buffer[LINE_SIZE];
  int i, j;
  char_grid_t sudoku;

  for (i = 0; i < GRID_SIZE; ++i) {
    fgets(buffer, sizeof(buffer) * GRID_SIZE, stdin);
    strcpy(sudoku.grid[i], buffer);
    sudoku.grid[i][LINE_SIZE - 1] = '\0';
  }

  return sudoku;
}

int_grid_t convert_grid_to_int(char_grid_t char_grid){
  int_grid_t int_grid;
  int i, j;

  for (i = 0; i < GRID_SIZE; ++i) {
    for (j = 0; j < LINE_SIZE; j+=2) {
      if(char_grid.grid[i][j] == 'X')
        int_grid.grid[i][j/2] = EMPTY;
      else
        int_grid.grid[i][j/2] = char_grid.grid[i][j] - '0';
    }
  }

  return int_grid;
}

void print_grid(int_grid_t int_grid){
  int i, j, is_pipe;

  for (i = 0; i < GRID_SIZE; ++i) {
    for (j = 0; j < GRID_SIZE; ++j) {
      /* printf("%2d", int_grid.grid[i][j]); */
      if(j == 8)
        is_pipe = j % 3;
      else
        is_pipe = (j + 1) % 3;
      printf((is_pipe == 0) ? "%d | " : (j == 8) ? "%d" : "%d ", int_grid.grid[i][j]);
    }
    if(i == 8)
      is_pipe = i % 3;
    else
      is_pipe = (i + 1) % 3;
    printf((is_pipe == 0) ? "\n- - - - - - - - - - -\n" : "\r\n");
  }
}

int main(int argc, char *argv[]){
  int i, j;

  char_grid_t temp_char_grid = read_grid();
  int_grid_t temp_int_grid = convert_grid_to_int(temp_char_grid);
  print_grid(temp_int_grid);

  return 0;
}
