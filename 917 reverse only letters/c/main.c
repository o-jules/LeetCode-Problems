#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define isLetter(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))

char* reverseOnlyLetters(char* S) {
  int size = strlen(S);
  char* newStr = calloc(size + 1, sizeof(char));
  newStr[size] = 0;

  int l = 0, r = size - 1;
  int isL = 0, isR = 0;

  while (l <= r) {
    isL = isLetter(S[l]);
    isR = isLetter(S[r]);

    if (isL && isR) {
      newStr[r] = S[l];
      newStr[l] = S[r];
      l++;
      r--;
    } else {
      if (!isL) {
        newStr[l] = S[l];
        l++;
      }
      if (!isR) {
        newStr[r] = S[r];
        r--;
      }
    }
  }

  return newStr;
}

int main() {
  char *s = "a-bC-dEf-ghIj";
  char *rs = reverseOnlyLetters(s);
  printf("%s\n", rs);
  free(rs);
  return 0;
}
