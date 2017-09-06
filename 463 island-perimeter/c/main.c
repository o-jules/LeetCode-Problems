#include <stdio.h>

int islandPerimeter(int **grid, int gridRowSize, int gridColSize)
{
  int p = 0;

  for (int i = 0; i < gridRowSize; i++)
  {
    for (int j = 0; j < gridColSize; j++)
    {
      if ((int)*(grid + i * gridColSize + j) == 0)
        continue;

      if (i == 0)
        p++;
      if (i == gridRowSize - 1)
        p++;
      if (j == 0)
        p++;
      if (j == gridColSize - 1)
        p++;
      if (i - 1 >= 0 && (int)*(grid + (i - 1) * gridColSize + j) == 0)
        p++;
      if (j - 1 >= 0 && (int)*(grid + i * gridColSize + j - 1) == 0)
        p++;
      if (i + 1 < gridRowSize && (int)*(grid + (i + 1) * gridColSize + j) == 0)
        p++;
      if (j + 1 < gridColSize && (int)*(grid + i * gridColSize + j + 1) == 0)
        p++;
    }
  }

  return p;
}

int main(void)
{

  int island[4][4] = {
    {0, 1, 0, 0},
    {1, 1, 1, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0}
  };

  /*
  {
      {0, 1, 0, 0},
      {1, 1, 1, 0},
      {0, 1, 0, 0},
      {1, 1, 0, 0},
  };
  */

  int p = islandPerimeter((int **)island, 4, 4);
  printf("%d\n", p);
}
