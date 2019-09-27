/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
  const map = {};
  const len = secret.length;
  for (let i = 0; i < len; i++) {
      const c = secret[i];
      if (map[c]) {
          map[c].count++;
          map[c].list.push(i);
      } else {
          map[c] = { count: 1, list: [i] };
      }
  }

  const not_match = [];
  let bull = 0, cows = 0;
  for (let i = 0; i < len; i++) {
      const c = guess[i];
      if (map[c]) {
          const j = map[c].list.indexOf(i);
          if (j >= 0) {
              bull++;
              map[c].count--;
          } else {
              not_match.push({ value: c, index: i });
          }
      }
  }

  for (let i = 0; i < not_match.length; i++) {
      const { value, index } = not_match[i];
      if (map[value].count > 0) {
          cows++;
          map[value].count--;
      }
  }

  return bull + 'A' + cows + 'B';
};
