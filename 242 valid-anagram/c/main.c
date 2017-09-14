#include <stdio.h>

/**
 * 最优的解法和 383 ransom-note 相类似。
 */
bool isAnagram(char* s, char* t) {
  int table[26] = {0};
  int l = strlen(s);
  while (l--) {
    table[s[l] - 'a'] ++;
  }

  l = strlen(t);
  while(l--) {
    if (table[t[l] - 'a'] > 0) {
      table[t[l] - 'a'] --;
    } else {
      return false;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (table[i] != 0) {
      return false;
    }
  }
  return true;
}

int main(void) {

}
