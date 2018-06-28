/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    nums.sort((l, r) => l - r);

    const len = nums.length - 1;
    let sum = 0;
    for (let i = 0; i < len;) {
      sum += nums[i];
      i += 2;
    }
    return sum;
};

console.log(
  arrayPairSum([6,2,1,2,3,4])
)
