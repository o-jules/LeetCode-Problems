/**
 * @param {number[]} A
 * @return {number}
 */
var peakIndexInMountainArray = function(A) {
  let len = A.length - 1;
  for (let i = 0; i < len; i++) {
    if (A[i] - A[i+1] > 0) {
      return i;
    }
  }
};
