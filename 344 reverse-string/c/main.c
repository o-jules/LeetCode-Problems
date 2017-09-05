char* reverseString(char* s) {
  int len = strlen(s) - 1;
  if (len > 0) {
      char c;
      for (int i = 0, j = len; i < j; i++, j--) {
          c = s[i];
          s[i] = s[j];
          s[j] = c;
      }
  }
  return s;
}
