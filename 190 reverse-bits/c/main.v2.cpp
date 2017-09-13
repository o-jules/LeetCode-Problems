/**
 * Leetcode上的解法
 * 平均时间复杂度稍逊，
 * 空间复杂度占优。
 */

uint32_t reverseBits(uint32_t n) {
  uint32_t ans;
  for (int i = 0; i < 32; ++i) {
      ans = (ans << 1) | (n & 1);
      n >>= 1;
  }
  return ans;
}
