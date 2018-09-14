/**
 * @param {string} S
 * @param {character} C
 * @return {number[]}
 */
var shortestToChar = function(S, C) {
  let len = S.length;
  let ret = new Array(len);

  let prev = -len-1;
  for (let i = 0; i < len; i++) {
      if (S.charAt(i) === C) {
          prev = i;
      }
      ret[i] = i - prev;
  }

  prev = len*2;
  for (let i = len - 1; i >= 0; i--) {
      if (S.charAt(i) === C) {
          prev = i;
      }
      ret[i] = Math.min(ret[i], prev - i);
  }

  return ret;
};
