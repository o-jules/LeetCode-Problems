#include <stdio.h>

#define bool int
#define false 0

bool isPowerOfTwo(int n) {
  if (n <= 0) return false;

  while (!(n&1)) {
    n >>= 1;
  }
  return n == 1;
}

void test(int n) {
  if (isPowerOfTwo(n)) {
    printf("yes: %d \n", n);
  } else {
    printf("no: %d \n", n);
  }
}

int main(void) {
  test(-3);
  test(-2);
  test(-1);
  test(0);
  test(1);
  test(2);
  test(3);
  test(4);
  test(5);
  test(6);
  test(7);
  test(8);
}
