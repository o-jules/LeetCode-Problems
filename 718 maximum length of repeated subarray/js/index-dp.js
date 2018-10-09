// 动态规划

/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number}
 */
var findLength = function(A, B) {
  const la = A.length;
  const lb = B.length;

  let max = 0;
  for (let i = 0; i < la; i++) {
    // prefix, (A, 0, i)
    for (let j = 0; j < lb; j++) {
      // prefix, (B, 0, j)
      const m = lcs(A, B, i, j);
      if (m > max) {
        max = m;
      }
    }
  }

  return max;
};

function lcs(A, B, i, j) {
  if (A[i] === B[j]) {
    return lcs(A, B, i - 1, j - 1) + 1;
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
