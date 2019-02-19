#include <stdio.h>
#include <string.h>

int firstUniqChar(char* s) {
  int count[26];
  int order[26];

  for(int i = 0; i < 26; i++) {
    count[i] = 0;
    order[i] = -1;
  }

  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    int j = s[i] - 'a';
    count[j]++;
    if (order[j] == -1) {
      order[j] = i;
    }
  }

  int pos = -1;
  for (int i = 0; i < 26; i++) {
    if (order[i] != -1 && count[i] == 1) {
      if (order[i] < pos || pos == -1) {
        pos = order[i];
      }
    }
  }

  return pos;
}

int main() {
  int i = firstUniqChar("loveleetcode");
  printf("unique = %d\n", i);
  return 0;
}
