int hammingDistance(int x, int y) {
  x = x ^ y;
  int zb = z;
  int c = 0;
  while (z) {
      zb = z >> 1 << 1;
      if (zb != z) {
          c ++;
      }
      z = z >> 1;
  }
  return c;
}
