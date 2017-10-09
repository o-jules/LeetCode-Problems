
// 暴力解法

var bulbSwitch = function(n) {
  if (n <= 0) return 0
  if (n <= 2) return 1

  // first step
  let bulbs = new Array(n).fill(true)

  for (let j = 2; j <= n; j++) {
    let i = j - 1
    while (i < n) {
      bulbs[i] = !bulbs[i]
      i += j
    }
  }

  let count = 0
  for (let i = 0; i < n; i++)
    bulbs[i] && count++

  return count
};

// 暴力法出现的问题：
// 时间较长，有可能超时
console.log(
  bulbSwitch(9999999)
)
// 2
