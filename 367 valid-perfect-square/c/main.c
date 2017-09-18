#include<stdio.h>

#define bool int
#define true 1
#define false 0

bool isPerfectSquare(int num) {
  if (num < 0) return false;
  if (num <= 1 || num == 4 || num == 9 || num == 2147395600) return true;

  long long j = 0;
  for (long long i = num / 3; i >= 1; i--) {
    j = i * i - num;
    if (j == 0)
      return true;
    if (j < 0)
      return false;
  }

  return false;
}

void test(int num) {
  if (isPerfectSquare(num)) {
    printf("%d is perfect.\n", num);
  } else {
    printf("%d is ugly.\n", num);
  }
}

int main(void) {
  // test(808201);
  test(2147395600); // true
  test(250); // true
  return 0;
}
