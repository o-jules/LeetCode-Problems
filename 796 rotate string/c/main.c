#include <stdio.h>
#include <string.h>
#include <assert.h>

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
  if (len == 1) {
    return A[0] == B[0];
  }

  int a, b;
  for (int i = 0; i < len; i++) {
    if (A[i] != B[0]) {
      continue;
    }

    for(a = i, b = 0; a < len; a++, b++) {
      if (A[a] != B[b]) {
        goto next;
      }
    }
    for (a = 0, b = len - i; a < i; a++, b++) {
      if (A[a] != B[b]) {
        goto next;
      }
    }
    return true;

    next: ;
  }

  return false;
}

int main() {
  assert(rotateString("", "") == 1);
  assert(rotateString("a", "a") == 1);
  assert(rotateString("ab", "ab") == 1);
  assert(rotateString("ab", "ba") == 1);
  assert(rotateString("abcde", "cdeab") == 1);
  assert(rotateString("abcde", "abced") == 0);
  assert(rotateString("abcde", "abcde") == 1);

  printf("All test cases are passed.\n");
}
