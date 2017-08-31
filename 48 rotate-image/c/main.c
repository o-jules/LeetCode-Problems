#include <stdio.h>
#include <stdlib.h>

/**
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * a b c
 *
 * transform to
 * a 7 4 1
 * b 8 5 2
 * c 9 6 3
 *
 *
 * a 7 4
 * 1 5 6
 * 2 8 9
 * 3 b c
 *
 */

// (row, col)
// m(x, y) = new_m(y, row - x)
//
// new_m(x, y) = m(y, col - x)


void rotate(int **matrix, int row, int col) {
  int *old = (int*) matrix;

  int *img = malloc(sizeof(int) * row * col);

  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      *(img + i * row + j) = *(old + (row - j - 1) * col + i);
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      *(old + i * col + j) = *(img + i * col + j);
    }
  }

  free(img);
}

int main(void) {
  int img[3][4] = {
    {1, 2, 3, 0},
    {4, 5, 6, 0},
    {7, 8, 9, 0}
  };

  int **s = (int **) img;
  rotate(s, 3, 4);

  for(int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", *(s + i * 3 + j));
    }
    printf("\n");
  }
}
