/**
 * 最优解 1
 */

int findComplement(int num) {
  num = ~num;

  int flag = 1 << 31;
  while (num & flag) {
      num &= (~flag);
      flag = flag >> 1;
  }
  return num;
}

/**
 * 最优解 2
 */
int findComplement(int num) {
  int mask = ~0;
  while (mask & num){
      mask <<= 1;
  }
  return ~mask & ~num;
}
