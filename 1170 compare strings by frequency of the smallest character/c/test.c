#include <stdio.h>

#include "main.h"

int main() {

  char *queries[4] = {"bbb","cc","yzffdd", "d"};
  char *words[5] = {"a","aa","aaa","aaaa", "hhhisiisii"};
  int size = 0;

  int *list = numSmallerByFrequency(queries, 4, words, 5, &size);
  for (int i = 0; i < size; i++) {
    printf("%d\n", list[i]);
  }
  return 0;
}
