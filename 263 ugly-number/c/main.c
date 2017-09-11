#include<stdio.h>

#define bool int
#define true 1

bool isUgly(int num) {
  if (num <= 0)
    return false;
  if (num == 1)
    return true;

  while (!(num%2)) num /= 2;
  while (!(num%3)) num /= 3;
  while (!(num%5)) num /= 5;

  return num == 1;
}

void test(int n) {
  if (isUgly(n)) {
    printf("ugly %d\n", n);
  } else {
    printf("pretty %d\n", n);
  }
}

int main(void) {
  test(4);
  test(6);
  test(9);
  test(14);
  test(25);

  return 0;
}
