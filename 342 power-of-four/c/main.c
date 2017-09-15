bool isPowerOfFour(int num) {
}
#include <math.h>

bool isPowerOfFour(int num) {
  double x = log2(num) / 2.0;
  num = (int)x;
  return (double)(num) == x;
}
