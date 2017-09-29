int findLengthOfLCIS(int *nums, int numsSize) {
  int max = 0;

  for (int i = 0; i < numsSize; i++) {
    int j = i;
    int len = 0;
    while (j < numsSize - 1 && nums[j + 1] > nums[j]) {
      j ++;
      len ++;
    }

    if (len + 1 > max) {
      max = len + 1;
    }
    i = i + len;
  }

  return max;
}
