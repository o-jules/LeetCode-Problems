/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function(S) {
  let d = 0;
  let s = "";
  for (let i = 0; i < S.length; i++) {
    if (S[i] == '(') {
      if (d++ !== 0) s += '(';
    } else {
      if (--d !== 0) s += ')';
    }
  }
  return s;
};
