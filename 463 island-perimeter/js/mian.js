
function islandPerimeter(grid, gridRowSize, gridColSize)
{
  let p = 0;

  let gridRowSize = grid.length
  let gridColSize = grid[0].length
  for (let i = 0; i < gridRowSize; i++)
  {
    for (let j = 0; j < gridColSize; j++)
    {
      if (grid[i][j] == 0)
        continue;

      if (i == 0)
        p++;
      if (i == gridRowSize - 1)
        p++;
      if (j == 0)
        p++;
      if (j == gridColSize - 1)
        p++;
      if (i - 1 >= 0 && grid[i - 1][j] == 0)
        p++;
      if (j - 1 >= 0 && grid[i][j - 1] == 0)
        p++;
      if (i + 1 < gridRowSize && grid[i + 1][j] == 0)
        p++;
      if (j + 1 < gridColSize && grid[i][j + 1] == 0)
        p++;
    }
  }

  return p;
}
