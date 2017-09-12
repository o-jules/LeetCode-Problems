#include<stdio.h>

// int: 32bit, unsigned
// 最直白的解法
int findComplement(int num) {
  if (num < 0)
    return 0;
  if (num == 0)
    return 1;

  int pad = 0;
  while(num > 0) {
    num <<= 1;
    pad ++;
  }

  num = (~num) >> pad;
  return num;
}

void test(int i) {
  printf("cmpl(%d) = %d\n", i, findComplement(i));
}

int main(void) {
  test(-1);
  test(0);
  test(1);
  test(5);
  return 0;
}
