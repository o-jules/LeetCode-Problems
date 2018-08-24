/**
 * @param {number} N
 * @return {number}
 */
var binaryGap = function(N) {
  var gap = 0;
  var pos = 0;
  var onePos = -1;

  while (N) {
    if (N & 1) {
      if (onePos >= 0) {
        gap = Math.max(gap, pos - onePos);
      }
      onePos = pos;
    }
    pos++;
    N = N >> 1;
  }

  return gap;
};

console.log(binaryGap(22))
console.log(binaryGap(5))
console.log(binaryGap(6))
console.log(binaryGap(8))
