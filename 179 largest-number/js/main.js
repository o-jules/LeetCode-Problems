/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
  // 需要注意的是 Javascript的sort方法 的使用
  nums = nums.sort((a, b) => {
    const i = parseInt(a + '' + b)
    const j = parseInt(b + '' + a)

    if (i < j) return 1
    if (i > j) return -1
    return 0
  })

  const s = nums.reduce((p, c) => p + c, '')
  return s[0] === '0' ? '0' : s
};





function test(arr) {
  console.log(
    largestNumber(arr)
  )
}

// test([3, 30, 34, 5, 9])
// test([0, 0]) // "00"

test([41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,
  97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,
  13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,
  78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,
  89,76,76,67,55])
