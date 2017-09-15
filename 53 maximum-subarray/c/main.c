#include<stdio.h>
#include<limits.h>

int maxSubArray(int* nums, int numsSize) {
  if (numsSize == 0) return 0;
  if (numsSize == 1) return nums[0];

  int sum = 0, max = INT_MIN;
  for (int i = 0; i < numsSize; i++) {
    sum = nums[i];
    if (sum > max) {
      max = sum;
    }
    for (int j = i + 1; j < numsSize; j++) {
      sum += nums[j];
      if (sum > max) {
        max = sum;
      }
    }
  }

  return max;
}

void test(int* arr, int c) {
  printf("%d\n", maxSubArray(arr, c));
}

int main(void) {
  /*
 int a[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
 test(a, 9);

 int b[1] = {2};
 test(b, 1);

 int c[2] = {1,2};
 test(c, 2);

 int d[12] = {1, 2, -3, 4, -5, 6, -4, 3, 2, -1, 8, 0};
 test(d, 12);
 */

 int e[9] = {-2,1,-3,4,-1,2,1,-5,4};
 test(e, 9); // 6

 int f[2] = {-2, -1};
 test(f, 2); // -1
}
