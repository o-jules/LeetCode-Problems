// O(m * n)

/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number}
 */
var findLength = function(A, B) {
  const la = A.length;
  const lb = B.length;
  const cache = new Array(la + 1).fill(null).map(i => new Array(lb + 1).fill(0));

  let cal = 0; // common array length
  let temp = 0;

  for (let i = 0; i < la; i++) {
    for (let j = 0; j < lb; j++) {
      if (A[i] === B[j]) {
        temp = cache[i][j] + 1;
        cache[i + 1][j + 1] = temp;
        if (temp > cal) {
          cal = temp;
        }
      } else {
        cache[i + 1][j + 1] = 0;
      }
    }
  }

  return cal;
};

const TestCases = [
  {
    A: [1,2,3,2,1],
    B: [3,2,1,4,7]
  }
]

TestCases.forEach(cs => {
  console.log(findLength(cs.A, cs.B))
})
