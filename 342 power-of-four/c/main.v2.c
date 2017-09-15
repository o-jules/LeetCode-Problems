/**
 * Leetcode上的最优解，
 * 没有用到math的函数
 */
bool isPowerOfFour(int num) {
  return num > 0 && ((num - 1) & num) == 0 && (num & 0x55555555) == num;
}

bool isPowerOfFour(int num) {
  return (num>0) && ((num & num-1) == 0) && ((num-1) % 3 == 0);

}
