/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
  if (num < 0) return []
  if (num === 0) return [0]

  let arr = new Array(num + 1).fill(0)
  arr[1] = 1

  let i = 2, j = 1
  let k = 2

  while (i <= num) {
    if (i == k) {
      arr[i] = j = 1
      k *= 2
    } else {
      arr[i] = 1 + arr[j]
      j++
    }

    i++
  }

  return arr
};


// test
// console.log(countBits(0))
console.log(countBits(1))
// console.log(countBits(2))
console.log(countBits(3))
console.log(countBits(4))
console.log(countBits(5))
console.log(countBits(6))
