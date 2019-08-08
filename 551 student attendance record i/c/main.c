
bool checkRecord(char * s){
  char *p = s;

  int a = 0, l = 0;
  while (*p) {
    if (*p == 'A') {
      if (a >= 1) { return false; }
      a++;
      l = 0;
    } else if (*p == 'L') {
      if (l >= 2) { return false; }
      l++;
    } else {
      l = 0;
    }
    p++;
  }


  return true;
}
