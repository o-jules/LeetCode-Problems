

char * reverseStr(char * s, int k){
  int len = strlen(s), k2 = k * 2;
  char t;

  for (int i = 0; i < len; i += k2) {
    int l = i;
    int r = i + k - 1;
    if (r >= len) {
      r = len - 1;
    }
    while (l < r) {
      t = s[l];
      s[l++] = s[r];
      s[r--] = t;
    }
  }
  return s;
}
