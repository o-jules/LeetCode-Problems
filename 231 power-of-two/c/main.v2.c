#include <stdio.h>

bool isPowerOfTwo(int n) {
  return !!n && n > 0 && !(n & n - 1);
}
