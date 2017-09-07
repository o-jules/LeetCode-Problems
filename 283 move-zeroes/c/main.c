#include <stdio.h>

// [0, 1, 0, 3, 13]
// [1, 1, 1, 0]
void moveZeroes(int* nums, int numsSize) {
  int *n = nums;

  for (int i = 0; i < numsSize; i++) {
    if (n[i] != 0)
      continue;

    for (int j = i + 1; j < numsSize; j++) {
      if (n[j] != 0 ) {
        n[i] = n[j];
        n[j] = 0;
        break;
      }
    }
  }
}

int main(void) {
  int a[] = {0, 1, 0, 3, 12};
  moveZeroes(a, 5);

  for (int i = 0; i < 5; i++) {
    printf("%d ", a[i]);
  }
}
