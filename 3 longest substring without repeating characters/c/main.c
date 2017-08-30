#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
  int count = 1, max = 0;
  char *i = s;
  char *p = i + 1;
  char *h;

  while (*i != '\0') {
    while (*p != '\0') {
      for (h = i; h != p; h++) {
        if (*h == *p) {
          if (count > max)
            max = count;
          count = 1;
          goto OUT;
        }
      }

      count ++;
      p ++;
    }

    OUT:
    if (*h == '\0')
      break;
    i = h + 1;
  }

  return max;
}

int main(void) {
  printf("%d\n", lengthOfLongestSubstring("pwwkew"));
  printf("%d\n", lengthOfLongestSubstring("abcabcbb"));

  return 0;
}
