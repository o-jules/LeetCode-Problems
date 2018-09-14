/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
var backspaceCompare = function(S, T) {
  const s_len = S.length;
  const t_len = T.length;

  let s_str = '';
  let t_str = '';

  let delCount = 0;
  for (let i = s_len - 1; i >= 0; i--) {
    if ('#' === S[i]) {
      delCount ++;
    } else {
      if (delCount > 0) {
        delCount --;
      } else {
        s_str += S[i];
      }
    }
  }

  delCount = 0;
  for (let i = t_len - 1; i >= 0; i--) {
    if ('#' === T[i]) {
      delCount ++;
    } else {
      if (delCount > 0) {
        delCount --;
      } else {
        t_str += T[i];
      }
    }
  }

  return s_str === t_str;
}

console.log(
  backspaceCompare('ab#c', 'ad#c')
)

console.log(
  backspaceCompare('ab##', 'c#d#')
)

console.log(
  backspaceCompare('a#c', 'b')
)
