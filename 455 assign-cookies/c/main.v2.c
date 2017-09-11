#include <stdlib.h>

/**
 * 此解法是对于饼干可以叠加的情况
 */

int compare (const void *lhs, const void *rhs) {
  return *(int*)lhs - *(int*)rhs;
}

int findContentChildren(int *g, int gSize, int* s, int sSize) {
  qsort(g, gSize, sizeof(int), compare);
  qsort(s, sSize, sizeof(int), compare);

  int i = 0, j = 0, acc = 0;

  for (; i < sSize; i++) {
    acc += s[i];
    if (acc >= g[j]) {
      j++;
      acc = 0;
    }

    if (j >= gSize) {
      break;
    }
  }

  return j;
}
