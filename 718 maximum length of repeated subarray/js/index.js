// O(m * n)

/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number}
 */
var findLength = function(A, B) {
  const la = A.length;
  const lb = B.length;
  let cal = 0; // common array length

  for (let i = 0; i < la; i++) {
    for (let j = 0; j < lb; j++) {
      let l = 0;
      while(i + l < la && j + l < lb && A[i + l] === B[j + l]) {
        l++;
      }

      if (l > cal) {
        cal = l;
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
