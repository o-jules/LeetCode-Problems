/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
  if (2 >= n) return 0;

  let primes = new Array(n).fill(true);

  let sqr = Math.floor(Math.sqrt(n - 1));
  for (let i = 2; i <= sqr; ++i) {
    if (primes[i]) {
      for (let j = i + i; j < n; j += i) {
        primes[j] = false;
      }
    }
  }

  let sum = 0;
  for (let i = 2; i < n; ++i) {
    sum += primes[i] ? 1 : 0;
  }
  primes = null;

  return sum;
};
