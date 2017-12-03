/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
  let sum = 1
  for (let i = m; i <= m + n - 2; i++) {
    sum *= i
  }

  for (let j = 1; j <= n - 1; j++) {
    sum /= j
  }

  return sum
};

console.log(uniquePaths(3, 3))
