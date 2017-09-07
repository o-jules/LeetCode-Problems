#include<stdio.h>

int addDigits(int num) {
  int newSum = 0;
  while (num >= 10) {
    newSum = 0;
    while (num) {
      newSum += num%10;
      num /= 10;
    }
    num = newSum;
  }

  return num;
}

int main(void) {
  printf("%d\n", addDigits(341));
}
