/**
 * @param {number} n
 * @return {number}
 */

var integerBreak = function(n) {
  if (n < 0) return 0
  if (n <=3) return n - 1
  if (n == 4) return 4

  let cache = new Array(n).fill(null)
  function innerMax(num) {
    if (num <= 4)
      return num

    let max = 1
    for (let i = 2; i < num; i++) {
      let m = i * (function(k) {
        if (!cache[k]) cache[k] = innerMax(k)
        return cache[k]
      })(num - i)

      if (m > max) {
        max = m
      }
    }

    return max
  }

  return innerMax(n)
};

// 10 => 2 , 3
console.log(integerBreak(2))
console.log(integerBreak(3))
console.log(integerBreak(4))
console.log(integerBreak(5))
console.log(integerBreak(6))
console.log(integerBreak(10))
console.log(integerBreak(12))
