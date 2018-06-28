/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
  const res = [];
  for (let i = 1, f = 0, b = 0; i <= n; i++) {
    f++;
    b++;
    if (f === 3 && b === 5) {
      res.push('FizzBuzz');
      f = 0;
      b = 0;
    } else if (f === 3) {
      res.push('Fizz');
      f = 0;
    } else if (b === 5) {
      res.push('Buzz');
      b = 0;
    } else {
      res.push('' + i);
    }
  }
  return res;
};

console.log(fizzBuzz(30))
