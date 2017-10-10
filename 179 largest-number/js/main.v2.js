/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
  nums.sort((a, b) => parseInt(b + '' + a) - parseInt(a + '' + b))

  const n = nums.join('')
  return n[0] === '0' ? '0': n
};
