/**
 * num: 0, 1, 2, ..., n
 * numes.size() = n
 * i:   0, 1, 2, ..., n - 1
 */
int missingNumber(int* nums, int numsSize) {
  int result = nums.size();

  int i = 0;
  for(int &num : nums) {
    result ^= num;
    result ^= i;
    i++;
  }

  return result;
}
