#include <stdio.h>
#include <math.h>

#define e 1e-6

// f(x) = x^2 - b
// f'(x) = 2*x
// x_{n+1} = x_{n} - f(x_n)/f'(x_n)

float mySqrt(int x) {
  if (x == 0)
    return 0;

  float a = x;
  float prev = -1;

  while (fabs(pow(a, 2) - (float)x) > 1e-4) {
    a = (a + (float)x / a)/2.0;
    if (prev == a) {  break; }
    prev = a;
  }

  return a;
};

void test(int x) {
  printf("sqrt(%d) = %f\n", x, mySqrt(x));
}

int main(void) {
  //test(2);
  //test(3);
  //test(8192);

  // 极值测试：
  test(2147395599); //Leetcode要求输出 46339， 当前是 46340
}
