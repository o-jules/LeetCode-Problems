/**
 * 暴力解法
 */
int arrangeCoins(int n) {
  if (n <= 0) return 0;

  int i = 1;
  while (true) {
    n -= i;
    if (n == 0) return i;
    if (n < 0)  return i - 1;
    i++;
  }
}
