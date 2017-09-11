#include<stdio.h>

#define uint32_t unsigned

int hammingWeight(uint32_t n) {
  int i = 0;
  while(n) {
    if (n&1) i++;
    n >>= 1;
  }
  return i;
}

void test(uint32_t n) {
  printf("%d, %d\n", n, hammingWeight(n));
}

int main(void) {
  test(11);
}
