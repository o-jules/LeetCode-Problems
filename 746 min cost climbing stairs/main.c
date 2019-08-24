
int search(int* cost, int costSize, int *rec) {
  if (costSize <= 1) {
    return 0;
  }

  if (rec[costSize - 1] < 0) {
    rec[costSize - 1] = search(cost + 1, costSize - 1, rec);
  }
  if (rec[costSize - 2] < 0) {
    rec[costSize - 2] = search(cost + 2, costSize - 1, rec);
  }

  int m1 = *cost + rec[costSize - 1];
  int m2 = *(cost + 1) + rec[costSize - 2];
  return m1 > m2 ? m2 : m1;
}

int minCostClimbingStairs(int* cost, int costSize) {
  if (costSize <= 1) {
    return 0;
  }

  int *rec = malloc(costSize * sizeof(int));
  for (int i = 0; i < costSize; i++) {
    rec[i] = -1;
  }

  int min = search(cost, costSize, rec);
  free(rec);
  return min;
}
