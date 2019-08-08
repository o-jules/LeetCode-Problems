
void freeSpace(int **gridA, int **gridB, int gridSize) {
    for (int i = 0; i < gridSize; i++) {
      free(gridA[i]);
      free(gridB[i]);
    }
    free(gridA);
    free(gridB);
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
  int colSize = *gridColSize;

  int firstFresh = 0;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < colSize; j++) {
      if (grid[i][j] == 1) {
        firstFresh++;
      }
    }
  }
  if (firstFresh == 0) {
    return 0;
  }

  int **gridA, **gridB, **cur, **next, **temp;
  gridA = (int **)malloc(sizeof(int*) * gridSize);
  gridB = (int **)malloc(sizeof(int*) * gridSize);
  for (int i = 0; i < gridSize; i++) {
    int *rowA = (int *)malloc(sizeof(int) * colSize);
    int *rowB = (int *)malloc(sizeof(int) * colSize);

    for (int j = 0; j < colSize; j++) {
      rowA[j] = rowB[j] = grid[i][j];
    }
    gridA[i] = rowA;
    gridB[i] = rowB;
  }
  cur = gridA, next = gridB;
  int prevFresh = firstFresh, fresh = 0;
  int minute = 0;

  while (prevFresh > 0) {
    fresh = 0;
    minute++;

    for (int i = 0; i < gridSize; i++) {
      for (int j = 0; j < colSize; j++) {
        if (cur[i][j] == 1) {
          if (
            (i - 1 >= 0       && cur[i - 1][j] == 2) ||
            (i + 1 < gridSize && cur[i + 1][j] == 2) ||
            (j - 1 >= 0       && cur[i][j - 1] == 2) ||
            (j + 1 < colSize  && cur[i][j + 1] == 2)
          ) {
            // next round it becomes rotten
            next[i][j] = 2;
          } else {
            next[i][j] = cur[i][j];
            fresh++;
          }
        } else {
          next[i][j] = cur[i][j];
        }
      }
    }

    if (fresh == prevFresh) {
      freeSpace(gridA, gridB, gridSize);

      return -1;
    } else {
      prevFresh = fresh;
      temp = cur;
      cur = next;
      next = temp;
    }
  }

  freeSpace(gridA, gridB, gridSize);

  return minute;
}
