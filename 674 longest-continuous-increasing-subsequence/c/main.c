
int findLengthOfLCIS(int* nums, int numsSize) {
  if (numsSize <= 0)
    return 0;

  int max = 1, incr = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > nums[i - 1]) {
      incr ++;
    } else {
      if (incr > max)
        max = incr;

      incr = 1;
    }
  }

  if (incr > max)
    max = incr;

  return max;
}
