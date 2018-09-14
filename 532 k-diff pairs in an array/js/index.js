/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function(nums, k) {
  if (k < 0) {
    return 0
  };

  let count = 0;
  const map = {};
  const len = nums.length;

  for (let i = 0; i < len - 1; i++) {
    for (let j = i + 1; j < len; j++) {
      if (Math.abs(nums[i] - nums[j]) === k) {
        const sum = nums[i] + nums[j]
        if (!map[sum]) {
          map[sum] = true;
          count ++;
        }
      }
    }
  }

  return count;
};


console.log(findPairs([3, 1, 4, 1, 5], 2))
console.log(findPairs([1, 2, 3, 4, 5], 1))
