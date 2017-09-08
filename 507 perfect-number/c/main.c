#include <stdio.h>

#define bool int
#define true 1
#define false 0

bool checkPerfectNumber(int num) {
  if (num <= 5)
    return false;

  int mid = num / 2, count = 0;
  int i = 2;
  while (i < mid) {
    if (num % i == 0) {
      mid = num/i;
      count += i + mid;

      if (count > num) return false;
    }
    i++;
  }

  return (num == count + 1);
}

int main(void) {
  if (checkPerfectNumber(28)) {
    printf("yea");
  }
}
