#include <stdio.h>

#define e 1e-6

// f(x) = x^2 - b
// f'(x) = 2*x
// x_{n+1} = x_{n} - f(x_n)/f'(x_n)

int mySqrt(int x) {
  if (x == 0)
    return 0;

  float a = x;
  while (a*a - x) {
    a = a - (a*a - x)/(2*a);
  }

  return a;
};

int main(void) {
  int x = 2;
  printf("%f", mySqrt(x));
}
