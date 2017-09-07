/*
 * 最优解法：
 *
 * 将非零值依次向前推进，并纪录零值总数，
 * 最后把数组从尾部算起的零值总数的位全变成零
 */

void moveZeroes(int* nums, int numsSize) {
  int j = 0;
  int zeroCount = 0;
  for(int i = 0; i < numsSize; i++) {
      if(nums[i] != 0) {
          nums[j] = nums[i];
          j++;
      } else {
          zeroCount++;
      }
  }

  for(int i = numsSize - 1; i > numsSize-1-zeroCount; i--) {
      nums[i] = 0;
  }
}
