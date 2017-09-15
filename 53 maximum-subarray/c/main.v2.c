/**
 * Leetcode最佳解法
 *
 */
int maxSubArray(int* nums, int numsSize) {
  int b = 0, sum = nums[0];

  for(int i = 0; i < numsSize; i++) {
    if(b > 0) {
      b += nums[i];
    } else {
      b = nums[i];
    }

    if(b > sum) sum = b;
  }

  return sum;
}
