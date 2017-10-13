#include <limits.h>

#define MAX(a, b) (a > b ? a : b)

int maxRotateFunction(int* A, int ASize) {
  if (ASize <= 1)
    return 0;

  int sum = 0;
  int fi = 0;
  for (int i = 0; i < ASize; i++) {
    sum += A[i];
    fi += A[i] * i;
  }

  int max = fi;
  for (int i = 1; i < ASize; i++) {
    fi = fi + sum - ASize * A[ASize - i];
    max = MAX(max, fi);
  }

  return max;
}

int main(void) {
  return 0;
}
