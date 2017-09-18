#include<stdio.h>

int guess(int num) {
  if (num == 5) return 0;
  if (num > 5) return 1;
  return -1;
};

int guessNumber(int n) {
  int l = 0, r = n;
  int mid = 0, s = 0;

  while (l < r) {
    mid = l + (r - l)/2;
    s = guess(mid);

    if (s == 0) {
      return mid;
    } else if (s == 1) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return l;
}

int main(void) {
  printf("%d\n", guessNumber(6));
}
