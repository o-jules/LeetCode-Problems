/**
 * @param {string} S
 * @param {character} C
 * @return {number[]}
 */
var shortestToChar = function(S, C) {
  const size = S.length;
  const distance = new Array(size);

  let lastIndex = null;
  for (let i = 0; i < size; i++) {
    if (S[i] === C) {
      lastIndex = i;
      distance[i] = 0;
    } else {
      distance[i] = lastIndex === null ? null : i - lastIndex;
    }
  }

  lastIndex = null;
  let r = null
  for (let i = size - 1; i >= 0; i--) {
    if (S[i] === C) {
      lastIndex = i;
    } else {
      if (lastIndex !== null) {
        r = lastIndex - i;
        if (distance[i] === null || r < distance[i]) {
          distance[i] = r;
        }
      }
    }
  }

  return distance;
};

console.log(
  shortestToChar('loveleetcode', 'e')
)
