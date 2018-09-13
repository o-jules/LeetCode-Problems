/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
var backspaceCompare = function(S, T) {
  const s_len = S.length;
  const t_len = T.length;
  const s_cache = new Array(s_len);
  const t_cache = new Array(t_len);

  let s_pos = 0;
  for (let i = 0; i < s_len; i++) {
    if ('#' === S[i]) {
      s_pos = Math.max(s_pos - 1, 0);
    } else {
      s_cache[s_pos] = S[i];
      s_pos ++;
    }
  }

  let t_pos = 0;
  for (let i = 0; i < t_len; i++) {
    if ('#' === T[i]) {
      t_pos = Math.max(t_pos - 1, 0);
    } else {
      t_cache[t_pos] = T[i];
      t_pos ++;
    }
  }

  if (s_pos !== t_pos) {
    return false;
  }

  for (let i = 0; i < s_pos; i++) {
    if (s_cache[i] !== t_cache[i]) {
      return false;
    }
  }

  return true;
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
