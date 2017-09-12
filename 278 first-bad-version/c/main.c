#include <stdio.h>

#define bool int
#define true 1

bool isBadVersion(int version) {
  return version >= 1702766719;//7;
}

int firstBadVersion(int n) {
  int r = n;
  int l = 1;
  int m;

  while(l < r) {
    m = l + (r - l) / 2;

    if (isBadVersion(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

void test(int n) {
  int i = firstBadVersion(n);
  printf("First: %d", i);
}

int main(void) {
  // test(8);
  test(2126753390);
}
