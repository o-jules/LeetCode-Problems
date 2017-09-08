#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 'a' - 'A' = 32
#define bool int
#define true 1
#define false 0

#define IS_CAPITAL(c) (c >= 'A' && c <= 'Z')
#define IS_ALPHNUM(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))

bool isPalindrome(char* s) {
  int len = strlen(s);
  if (len == 0 || len == 1)
    return true;

  int l = 0, r = len - 1;
  char cl = 0, cr = 0;

  while (true) {
    do {
      cl = s[l++];
      if (IS_CAPITAL(cl)) cl += 32;
    } while (!IS_ALPHNUM(cl) && (l <= 1 + r));

    do {
      cr = s[r--];
      if (IS_CAPITAL(cr)) cr += 32;
    } while (!IS_ALPHNUM(cr) && (l <= 1 + r));

    if (l > 1 + r) break;
    if (IS_ALPHNUM(cl) && IS_ALPHNUM(cr) && cl != cr)
      return false;
  }

  return true;
}

void test(char *s) {
  if (isPalindrome(s)) {
    printf("yes! %s\n", s);
  } else {
    printf("no! %s\n", s);
  }
}

int main(void) {
  test("a.");
  test("0P");
  test("1hA0l0ah1.");
}
