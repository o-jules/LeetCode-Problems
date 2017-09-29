#include <stdio.h>

/**
 * 返回新长度，并改变数组中的数的值
 */
int removeDuplicates(int* nums, int numsSize) {
  if (numsSize <= 0)
    return 0;
  if (numsSize <= 1)
    return 1;

  int t = nums[0];
  int i = 1, j = 0, c = 1;

  while (i < numsSize) {
    if (nums[i] != t) {
      nums[++j] = nums[i];
      t = nums[i];
      c++;
    }

    i++;
  }

  return c;
}

int main(void) {
  int nums[] = {1, 1, 1, 2, 2, 3, 4, 4, 5, 6};
  int len = removeDuplicates(nums, 10);

  printf("%d\n", len);
  for (int i = 0; i < len; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}
