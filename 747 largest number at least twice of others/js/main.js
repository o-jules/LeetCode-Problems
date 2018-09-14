/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function(nums) {
  const len = nums.length;

  let largest = -Infinity;
  let largestIndex = 0;

  for (let i = 0; i < len; i++) {
    if (nums[i] > largest) {
      largest = nums[i];
      largestIndex = i;
    }
  }

  for (let i = 0; i < len; i++) {
    if (nums[i] != largest) {
      if (largest < nums[i] * 2) {
        return -1;
      }
    }
  }

  return largestIndex;
};

// 时间复杂度：O(2n)
// 空间复杂度：O(1)

console.log(
  dominantIndex([4,3,1,0])
)

console.log(
  dominantIndex([2,6,3,1,0])
)

console.log(
  dominantIndex([4,2,1,0])
)

console.log(
  dominantIndex([1])
)
