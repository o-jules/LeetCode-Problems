/**
 * @param {string} S
 * @return {number[][]}
 */
var largeGroupPositions = function(S) {
  const pos = [];
  const len = S.length;
  if (len <= 2)
    return pos;

  var c = S[0], p = 0;
  for (let i = 1; i < len; i++) {
    if (c === S[i]) {
      if (i === len - 1 && i - p >= 2) {
        pos.push([p, i]);
     }
    } else {
      if (i - p >= 3) {
        pos.push([p, i - 1]);
      }
      c = S[i];
      p = i;
    }
  }
  return pos;
};

// console.log(largeGroupPositions('abbxxxxzyy'))
console.log(largeGroupPositions('abbxxxxzyyy'))
