/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
  const len = nums.length;

  if (len < 2) {
    return -1;
  }

  let lsum = 0;
  let rsum = 0;
  for (let i = 1; i < len; i++) {
    rsum += nums[i];
  }

  if (rsum === 0) {
    return 0;
  }

  for (let i = 1; i < len; i++) {
    lsum += nums[i - 1];
    rsum -= nums[i];
    if (lsum === rsum) {
      return i;
    }
  }

  return -1;
};


console.log(
  pivotIndex([1, 7, 3, 6, 5, 6])
)


console.log(
  pivotIndex([-1,-1,-1,0,1,1])
)
