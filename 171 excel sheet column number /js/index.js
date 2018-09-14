/**
 * @param {string} s
 * @return {number}
 */

const CODE_A = 'A'.charCodeAt(0);

function baseOf(c) {
  const code = c.charCodeAt(0);
  return code - CODE_A + 1;
}

var titleToNumber = function(s) {
  const list = s.split('').reverse();
  let count = 0;
  for (let i = 0; i < list.length; i++) {
      count += Math.pow(26, i) * baseOf(list[i]);
  }
  return count;
};

console.log(
  titleToNumber('ZY')
)
