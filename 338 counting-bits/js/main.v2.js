/**
 * @param {number} num
 * @return {number[]}
 */

// 由基本算法优化后的算法，
// Leetcode最优解

var countBits = function(num) {
  if (num < 0) return []

  const res = Array(num + 1).fill(0)
  for (let i = 1; i <= num; i++) {
    res[i] = res[i >> 1] + (i & 1)
  }

  return res
};
