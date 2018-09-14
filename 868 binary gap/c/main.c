int binaryGap(int N) {
  int gap = 0;
  int i = 0;
  int met = 0;

  while (N) {
    if (N & 1) {
      if (met) {
        if (i > gap) {
          gap = i;
        }
      } else {
        met = 1;
      }
      i = 0;
    }
    i++;
    N = N >> 1;
  }

  return gap;
}
