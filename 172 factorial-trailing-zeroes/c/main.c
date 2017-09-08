#include <stdio.h>

int trailingZeroes(int n) {
  if (n <= 0) {
    return 0;
  }

  int c = 0;
  int i = 5;
  while (i <= n) {
    c += n/i;
    i *= 5;
    // printf("%d, %d\n", n, i);
  }
  return c;
}

// test cases:
// 此解法不能通过测试
// 1808548329 -> 452137076
// （结果是452137078）
//
// 为什么？
// 因为 i *= 5 越界了。

void test(int n) {
  printf("tz(%d) = %d\n", n, trailingZeroes(n));
}

int main(void) {
  test(0);
  test(1);
  test(10);
  test(25);
  test(1808548329);
}
