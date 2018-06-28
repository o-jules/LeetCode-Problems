/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
  const res = new Array(n);

  for (let i = 0, j = 0; i < n; i++) {
    j++;
    if (j === 15) {
      res[i] = 'FizzBuzz';
      j = 0;
    } else if (j === 3 || j === 6 || j === 9 || j === 12) {
      res[i]  = 'Fizz';
    } else if (j === 5 || j === 10) {
      res[i]  = 'Buzz';
    } else {
      res[i] = '' + (i + 1);
    }
  }

  return res;
};

console.log(fizzBuzz(15))
