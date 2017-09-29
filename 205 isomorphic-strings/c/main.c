#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

// 假设全都是小写和数字，或大小写有区别
bool isIsomorphic(char* s, char* t) {
  int l = strlen(s), r = strlen(t);

  if (l != r)
    return false;

  char map[128] = { 0 };
  char exists[128] = { 0 };

  int j, k;
  for (int i = 0; i < l; i++) {
    j = s[i];

    if (map[j]) {
      if (map[j] != t[i])
        return false;
    } else {
      k = t[i];
      if (exists[k])
        return false;

      exists[k] = 1;
      map[j] = t[i];
    }
  }

  return true;
}

void test(char *l, char *r) {
  if (isIsomorphic(l, r)) {
    printf("%s || %s\n", l, r);
  } else {
    printf("%s /| %s\n", l, r);
  }
}

int main(void) {
  test("paper", "title");
  test("foo", "bar");
  test("egg", "add");

  test("salam", "tihih");

  test("13", "42");
}
