/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
  const size = nums.length;
  if (size <= 1) {
      return false;
  }

  const set = new Set();
  for (let i = 0; i < size; i++) {
      if (set.has(nums[i])) {
          return true;
      }
      set.add(nums[i]);
  }
  return false;
};
