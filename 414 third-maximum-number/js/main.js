/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
  let len = nums.length

  if (len <= 0)
    return null

  let max = [ null, null, null ];
  for (let i = 0; i < len; i++) {
    if (nums[i] === max[0] || nums[i] === max[1] || nums[i] === max[2]) {
      continue;
    }

    if (max[0] === null) {
      max[0] = nums[i]
    } else if (nums[i] > max[0]) {
      max[2] = max[1]
      max[1] = max[0]
      max[0] = nums[i]
    } else if (max[1] === null) {
      max[1] = nums[i]
    } else if (nums[i] > max[1]) {
      max[2] = max[1]
      max[1] = nums[i]
    } else if (max[2] === null) {
      max[2] = nums[i]
    } else if (nums[i] > max[2]) {
      max[2] = nums[i]
    }
  }

  if (max[2] !== null) {
    return max[2]
  }

  return max[0]
};

console.log(thirdMax([1]))
console.log(thirdMax([1, 2]))
console.log(thirdMax([3, 2, 1]))
console.log(thirdMax([2, 2, 3, 1]))
console.log(thirdMax([1, 1, 1, 2]))
console.log(thirdMax([1, 2, 2, 5, 3, 5]))
console.log(thirdMax([5, 2, 2]))
