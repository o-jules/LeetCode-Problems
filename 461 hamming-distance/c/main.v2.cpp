int hammingDistance(int x, int y) {
  x ^= y;
  y = 0;
  while (x) {
      if (x&1) y++;
      x = x >> 1;
  }
  return y;
}
