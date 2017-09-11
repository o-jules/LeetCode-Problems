#include <stdio.h>
#include <stdlib.h>

int compare (const void *lhs, const void *rhs) {
  return *(int*)lhs - *(int*)rhs;
}

int findContentChildren(int *g, int gSize, int* s, int sSize) {
  qsort(g, gSize, sizeof(int), compare);
  qsort(s, sSize, sizeof(int), compare);

  int j = 0;
  for (int i = 0; i < sSize; i++) {
    if (s[i] >= g[j]) j++;
    if (j >= gSize) break;
  }

  return j;
}

int main(void) {
  int g[] = {1, 2};
  int s[] = {1, 2, 3};

  int c = findContentChildren(g, 2, s, 3);
  printf("%d\n", c);
}
