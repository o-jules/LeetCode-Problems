#include<stdio.h>
#include<math.h>

#define bool int

bool isPowerOfThree(int n) {
  double x = log10(n) / log10(3);

  return x == (double)((int)x);
}

void test(int n) {
  if (isPowerOfThree(n)) {
    printf("yes %d\n", n);
  } else {
    printf("no %d\n", n);
  }
}

int main(void) {
  test(3);
  test(6);
  test(9);
}
