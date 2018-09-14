/**
 * @param {number} N
 * @return {number}
 */
var binaryGap = function(N) {
  var gap = 0;
  var i = 0;
  var met = false;

  while (N) {
    if (N & 1) {
      if (met) {
        gap = Math.max(gap, i);
      } else {
        met = true;
      }
      i = 0;
    }
    i++;
    N = N >> 1;
  }

  return gap;
};

// console.log(binaryGap(22))
// console.log(binaryGap(5))
// console.log(binaryGap(6))
console.log(binaryGap(8))
