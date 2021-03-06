#include <stdio.h>

// 检测一个字符串里的所有单词

int detectCapitalUse(char* word) {
  int length = strlen(word);
  int c = 0;

  int i = 0;
  int f = 0, // 首字母大写
      a = 0; // 全大写

  while (c < length) {
    if (word[c] == ' ') {
      f = a = 0;
      i = 0;
      c++;
      continue;
    }

    if (word[c] >= 'A' && word[c] <= 'Z') {
      if (i == 0) {
        f = 1;
      } else if(i == 1) {
        if (f)
          a = 1;
        else
          return 0;
      } else {
        if (!a) {
          return 0;
        }
      }
    } else {
      if (a) {
        return 0;
      }
    }

    c++;
    i++;
  }

  return 1;
}

// "FFFFFFFFFFFFFFFFFFFFf"
int main(void) {
  if (detectCapitalUse("FFFFFFFFFFFFFFFFFFFFf")) {
    printf("yes");
  } else {
    printf("no");
  }
}
