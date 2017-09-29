#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
  int j = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != val) {
      nums[j++] = nums[i];
    }
  }

  return j;
}

int main(void) {
  int nums[] = {1, 1, 1, 2, 2, 3, 4, 4, 5, 6};
  int len = removeElement(nums, 10, 1);

  printf("%d\n", len);
  for (int i = 0; i < len; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}
