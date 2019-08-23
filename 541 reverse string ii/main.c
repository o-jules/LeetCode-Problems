

char * reverseStr(char * s, int k){
  int i = 0, j = 0, count = 0, k2 = k * 2;
  char t;
  while (s[i]) {
    count++;
    if (s[++i] == '\0' || count == k2) {
      int gap = count > k ? k : count;

      for (int l = j, r = j + gap - 1; l < r; l++, r--) {
        t = s[l];
        s[l] = s[r];
        s[r] = t;
      }

      j = i;
      count = 0;
    }
  }
  return s;
}
