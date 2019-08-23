
char * reverseWords(char * s){
  if (!s[0] || !s[1]) {
    return s;
  }

  int i = 0, b = 0, e = 0;
  char t;
  while (s[i]) {
    if(s[i++] == 32 || s[i] == '\0') {
      e = s[i] == '\0' ? i - 1 : i - 2;
      for (int j = b, k = e; j < k; j++, k--) {
        t = s[k];
        s[k] = s[j];
        s[j] = t;
      }
      b = i;
    }
  }

  return s;
}
