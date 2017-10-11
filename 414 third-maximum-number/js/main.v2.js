/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
  let max1 = nums[0];
  let max2 = -Infinity, max3 = -Infinity;

  for (let i = 1; i < nums.length; i ++) {
      if (nums[i] > max1) {
          max3 = max2;
          max2 = max1;
          max1 = nums[i];
      } else if (nums[i] < max2 && nums[i] > max3) {
          max3 = nums[i]
      } else if (nums[i] < max1 && nums[i] > max2) {
          max3 = max2
          max2 = nums[i];
      }
  }
  return max3 === -Infinity ? max1 : max3
};

// 这个算法的问题：
// 不能避免序列值第3小的数是 -Infinity 的情况。
// 即： [1, 0, -Infinity] 应该返回 -Infinity，但返回了 max1
