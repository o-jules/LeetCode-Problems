/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
  const jewels = {};
  J.split('').forEach(i => jewels[i] = 1);

  let count = 0;
  S.split('').forEach(i => {
    if (jewels[i]) {
      count ++;
    }
  })
  return count;
};

console.log(
  numJewelsInStones('z', 'aAAbbb')
)
