/**
 * Leetcode上最佳解
 */
bool isPerfectSquare(int num) {
  if (num <= 0)
    return false;

  // sqrt(2147483647) = 46340.95
  int beg = 1, end = 46340;
  int mid;
  int temp;
  while (beg <= end) {
      mid = (beg + end) >> 1; //平均
      temp = mid * mid;
      if (temp == num)
        return true;
      else {
          if (temp < num)
            beg = mid + 1;
          else
            end = mid - 1;
      }
  }
  return false;
}
