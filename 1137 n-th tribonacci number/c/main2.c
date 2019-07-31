
int tribonacci(int n){
  if (n == 0 || n == 1) {
      return n;
  }
  if (n == 2) {
      return 1;
  }

  int t0 = 0, t1 = 1, t2 = 1;
  int j = 2;
  int t = 0;
  while (j < n) {
    t = t0 + t1 + t2;
    t0 = t1;
    t1 = t2;
    t2 = t;
    j++;
  };
  return t2;
}

