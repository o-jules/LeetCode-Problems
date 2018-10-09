// 使用缓存的 动态规划

/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number}
 */
var findLength = function(A, B) {
  const la = A.length;
  const lb = B.length;

  let max = 0;
  let m = 0;
  const cache = [];
  for (let i = 0; i < la; i++) {
    if (!cache[i]) {
      cache[i] = new Array(lb).fill(null);
    }
  }

  for (let i = 0; i < la; i++) {
    // prefix, (A, 0, i)

    for (let j = 0; j < lb; j++) {
      // prefix, (B, 0, j)
      m = lcs(A, B, i, j, cache);
      if (m > max) {
        max = m;
      }
    }
  }

  return max;
};

function lcs(A, B, i, j, cache) {
  if (i < 0 || j < 0) {
    return 0;
  }

  if (A[i] === B[j]) {
    if (i - 1 < 0 || j - 1 < 0) {
      return 1;
    }
    if (cache[i - 1][j - 1] === null) {
      const m = lcs(A, B, i - 1, j - 1, cache);
      cache[i - 1][j - 1] = m;
      return m + 1;
    } else {
      return cache[i - 1][j - 1] + 1;
    }
  }

  return 0;
}

const TestCases = [
  {
    A: [1,2,3,2,1],
    B: [3,2,1,4,7]
  }
]
TestCases.forEach(cs => {
  console.log(findLength(cs.A, cs.B))
})
