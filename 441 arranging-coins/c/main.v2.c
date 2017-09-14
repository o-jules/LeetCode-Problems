#include<stdio.h>
#include<math.h>

#define FL long double

/*
数学法：

f(i)   = (1 + i) * i / 2
f(i+j) = (1 + i + j) * (i + j)/2

  f(i + j) - f(i)
= (1 + i + j) * (i + j) - (1 + i) * i
= i + j + i^2 + ij + ji + j^2 - i - i^2
= (j + 2ij + j^2) /2

设 n <= f(1 + j)
  n - f(1) <= f(1 + j) - f(1) = (3j + j^2)/2
  =>
  n - 1 <= (3j + j^2) /2
  =>
  n - 1 <= ((j + 3/2)^2 - 9/4)/2
  =>
  n - 1 + 9/8 <= (j+3/2)^2 / 2
  =>
  sqrt(n + 1/8) * sqrt(2) <= j + 3/2
  =>
  sqrt(n + 1/8) * sqrt(2) - 3/2 <= j

**注意：此方法Leetcode的C编译器不支持足够的精度**
*/

int arrangeCoins(int n) {
  if (n <= 0) return 0;

  FL f = sqrt((FL) n + 0.125) * sqrt((FL)2.0) - (FL)1.5;
  int i = (int) f;
  i = f == (FL)i ? i : (i + 1);
  return i;
}

void test(int n) {
  printf("arrange(%d) = %d\n", n, arrangeCoins(n));
}

int main(void) {
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
  test(9);
  test(10);
  test(11);
  test(15);
  test(11434);
}
