bool hasAlternatingBits(int n) {
  int i = -1;
  while (n) {
    if (n & 1) {
      if (i == 1) {
        return false;
      }
      i = 1;
    } else {
      if (i == 0) {
        return false;
      }
      i = 0;
    }
    n = n >> 1;
  }

  return true;
}
