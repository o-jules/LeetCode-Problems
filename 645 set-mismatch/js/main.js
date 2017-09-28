// 注意 Javascript的 sort 函数

var findErrorNums = function(nums) {
  nums.sort((l, r) => l - r)
  let d = 0 // duplicate
  let len = nums.length -  1
  console.log(nums)

  let g =  (len + 1) ^ nums[len]
  let i
  for (i = 0; i < len; i++) {
    if (nums[i] == nums[i+1]) d = nums[i]

    g ^= (i + 1)
    g ^= nums[i]
  }
  // g = d ^ missing
  return [d, d^g]
};

console.log(
  findErrorNums([1,2,2,4])
)
