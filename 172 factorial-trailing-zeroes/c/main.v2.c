#include <stdio.h>

int trailingZeroes(int n) {
  int c = 0;
  while (n >= 5) {
    n /= 5;
    c += n;
  }

  return c;
}

void test(int n) {
  printf("tz(%d) = %d\n", n, trailingZeroes(n));
}

int main(void) {
  test(0);
  test(5);
  test(10);
  test(25);
  test(1808548329);
}
