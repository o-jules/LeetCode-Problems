/**
 * @param {number[]} A
 * @return {number}
 */

// F(i + 1) = F(i) + SUM - A[n - i] * n

var maxRotateFunction = function(A) {
  let len = A.length
  if (len <= 1) return 0

  let max = -Infinity
  let sum = 0
  let fi = 0
  for (let i = 0; i < len; i++) {
    sum += A[i]
    fi += A[i] * i
  }

  max = Math.max(max, fi)
  for (let i = 1; i < len; i++) {
    fi = fi + sum - len * A[len - i]
    max = Math.max(max, fi)
  }

  return max
};

function test(arr) {
  console.log('max is', maxRotateFunction(arr))
}

test([])
test([1])
test([4, 3, 2, 6])
