/**
 * 数学法2
 * f(i) >= n
 * i^2 + i >= 2n
 * (i+1/2)^2 - 1/4 >= 2n
 * i + 1/2 >= sqrt(2n + 1/4)
 * i >= sqrt(2n + 1/4) - 1/2
 */

int arrangeCoins(int n) {
  if (n <= 0)
    return 0;

  long long nll = n;
  return (int) floor(sqrt(2.0 * nll + 0.25) - 0.5);
}
