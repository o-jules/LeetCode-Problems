#include <stdio.h>
#include <string.h>

#define bool int;
#define true 1;
#define false 0;

bool rotateString(char* A, char* B) {
  int len = strlen(A);
  if (len != strlen(B)) {
    return false;
  }
  if (len == 0) {
    return true;
  }
  for (int i = 0; i < len; i++) {
    /**/
    int j = i, k = 0;
    while (j < (len + i)) {
      if (B[k] != A[j%len]) {
        goto next;
      }
      j++;
      k++;
    }
    return true;

    next:
      continue;
  }

  return false;
}

int main() {
  printf("%d\n", rotateString("abcde", "cdeab"));
  printf("%d\n", rotateString("abcde", "abced"));
  printf("%d\n", rotateString("abcde", "abced"));
}
