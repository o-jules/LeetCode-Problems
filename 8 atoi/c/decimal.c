#include <stdio.h>
#include <limits.h>

/**
 * 正负
 * 科学计数法
 */

 int myAtoi(char *str) {
  int sign = 1, integer = 0;
  int i = 0;
  char *c = str;
  int tmp = 0;

  while (*c != '\0') {
    if (i == 0) {
      switch (*c) {
        case ' ':
        case '0':
          goto NEXT_CHAR;
        case '-':
          sign = -1;
          goto CONTINUE;
        case '+':
          goto CONTINUE;
      }
    }

    if (*c >= '0' && *c <= '9') {
      // 溢出检测:
      tmp = *c - '0';
      if (sign == 1) {
        if (integer > INT_MAX/10 ||
            INT_MAX - integer * 10 <= tmp) {
          return INT_MAX;
        }
      }
      if (sign == -1) {
        if (
          -integer < INT_MIN/10 ||
          INT_MIN + integer * 10 >= -tmp) {
          return INT_MIN;
        }
      }

      integer = integer * 10 + (*c - '0');
    } else {
      break;
    }

    CONTINUE:
    i++;

    NEXT_CHAR:
    c++;
  }

  return integer * sign;
}

// 测试
// "+-1"
// "-+1"
// "+1d"
// "+0.0"
// "    010" -> 10
// "   +0 123" -> 0
// "2147483648" -> 2147483647
// "    -10326662300y" -> -2147483648 (-1736727708)

int main(void) {
  // printf("%d\n", myAtoi("-1"));
  printf("%d\n", myAtoi("    -10326662300y"));

}
