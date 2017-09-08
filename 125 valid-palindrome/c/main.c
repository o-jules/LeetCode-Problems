#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define IS_CAPITAL(c) (c >= 'A' && c <= 'Z')
#define IS_ALPHNUM(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))

bool isPalindrome(char* s) {
  int len = strlen(s);
  if (len <= 1) return true;

  int l = 0, r = len - 1;
  char cl = 0, cr = 0;

  while (true) {
    do {
      cl = s[l++];
    } while (!(IS_ALPHNUM(cl) || l > 1 + r));
    if (l > 1 + r) break;

    do {
      cr = s[r--];
    } while (!(IS_ALPHNUM(cr) || l > 1 + r));
    if (l > 1 + r) break;

    if (IS_CAPITAL(cl)) cl += 32;
    if (IS_CAPITAL(cr)) cr += 32;
    if (cl != cr)
      return false;
  }

  return true;
}

// test case:
// A man, a plan, a canal: Panama
// ""
// "0P" -> false
// "a." -> true
// ".," -> true

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
