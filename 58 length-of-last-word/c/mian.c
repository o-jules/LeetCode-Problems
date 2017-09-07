int lengthOfLastWord(char* s) {
  char *c = s;
  int prev = 0,
      cur = 0;

  while (*c != '\0') {
    if (*c == ' ') {
      if (cur != -1) {
        prev = cur;
      }
      cur = -1;
    } else {
      if (cur == -1)
        cur = 0;
      cur ++;
    }
    c++;
  }
  return cur == -1 ? prev: cur;
}
