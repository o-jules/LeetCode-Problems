
int minCostClimbingStairs(int* cost, int costSize) {
  if (costSize <= 1) {
    return 0;
  }

  int m1 = *cost + minCostClimbingStairs(cost + 1, costSize - 1);
  int m2 = *(cost + 1) + minCostClimbingStairs(cost + 2, costSize - 2);

  return m1 > m2 ? m2 : m1;
}
