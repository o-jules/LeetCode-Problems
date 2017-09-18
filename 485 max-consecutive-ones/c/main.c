int findMaxConsecutiveOnes(int *nums, int numsSize) {
  int max = 0, c = 0;

  while (numsSize--) {
    if (nums[numsSize] == 1) {
      c++;
    } else {
      if (c > max) max = c;
      c = 0;
    }
  }

  return max;
}
