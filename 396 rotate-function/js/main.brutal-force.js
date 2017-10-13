/**
 * @param {number[]} A
 * @return {number}
 */

/**
 * 暴力解法
 * 超时
 */
var maxRotateFunction = function(A) {
  let len = A.length
  if (len <= 0) return 0

  let i = 0
  let max = -Infinity
  for (;i < len; i++) {
    let val = 0
    for (let j = 0; j < len; j++) {
      val += A[(i + j) % len] * j
    }
    max = Math.max(val, max)
  }
  return max
};

function test(arr) {
  console.log('max is', maxRotateFunction(arr))
}
