#include <stdio.h>
#include <string.h>

#define SPACE ' '

int countSegments(char* s) {
  int i = strlen(s);
  if (i <= 0) return 0;

  int c = 0;
  int prevIsSpace = 1;
  while (i--) {
    if (s[i] == ' ') {
      prevIsSpace = 1;
    } else {
      if (prevIsSpace) c++;
      prevIsSpace = 0;
    }
  }

  return c;
}

void test(char *s) {
  printf("seg(`%s`) = %d\n", s, countSegments(s));
}

int main(void) {
  test("Hello, my name is John");
  test("  ");
  test("  Hello, word");
  test("  H,   00    ");

  return 0;
}
