/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
  const tokenList = str.split(" ");
  const len = pattern.length;
  if (tokenList.length !== len) {
    return false;
  }

  const mapTp = {};
  const mapPt = {};
  for (let i = 0; i < len; i++) {
    let p = mapTp[tokenList[i]];
    let q = mapPt[pattern[i]];
    if (!p && !q) {
      mapTp[tokenList[i]] = pattern[i];
      mapPt[pattern[i]] = tokenList[i];
    } else {
      if (p !== pattern[i] || q !== tokenList[i]) {
        return false;
      }
    }
  }
  return true;
};

console.log(
  wordPattern('abbc', 'dog cat cat dog')
)
