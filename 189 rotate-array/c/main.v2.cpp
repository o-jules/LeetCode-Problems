/**
 * Leetcode 最优解示例
 *
 * 时间复杂度O(n)
 * 空间复杂度O(1)
 *
 */
void reverse(vector<int>& nums, int start, int end) {
  int temp;

  while (start < end) {
    temp = nums[start];
    nums[start] = nums[end];
    nums[end] = temp;
    start++;
    end--;
  }
}

void rotate(vector<int>& nums, int k) {
  int lenth = nums.size();
  if(lenth <= 1) {
    eturn;
  }

  k=k%lenth;
  reverse(nums, 0, lenth - k - 1);
  reverse(nums, lenth - k, lenth - 1);
  reverse(nums, 0, lenth - 1);
}
