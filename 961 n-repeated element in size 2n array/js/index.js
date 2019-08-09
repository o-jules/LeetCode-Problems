/**
 * @param {number[]} A
 * @return {number}
 */
var repeatedNTimes = function(A) {
  const s = new Set();
  for (let i = 0; i < A.length; i++) {
      if (s.has(A[i])) {
          return A[i];
      }
      s.add(A[i]);
  }
};
