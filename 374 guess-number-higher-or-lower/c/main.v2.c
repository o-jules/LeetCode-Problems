// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

int guess(int num);

/**
 * Leetcode 最优解
 */
int guessNumber(int n)
{
  int lo = 1;
  int hi = n;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    int g = guess(mid);
    if (g == 0)
      return mid;
    if (g == -1)
      hi = mid - 1;
    if (g == 1)
      lo = mid + 1;
  }
  return lo;
}
