

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStones(int a, int b, int c, int* returnSize){
  *returnSize = 2;
  int *res = malloc(sizeof(int) * 2);

  int t;
  if (a < b) {
    t = a; a = b; b = t;
  }
  if (a < c) {
    t = a; a = c; c = t;
  }
  if (b < c) {
    t = b; b = c; c = t;
  }
  // now a >= b >= c

  // get min
  res[0] = 0;
  if (a - b == 2 || b - c == 2) {
    res[0] = 1;
  } else {
    if (a - b > 1) {
      res[0]++;
    }
    if (b - c > 1) {
      res[0]++;
    }
  }

  // max
  if (min == 0) {
    res[1] = 0;
  } else {
    res[1] = (a - b - 1) + (b - c - 1);
  }
  return res;
}
