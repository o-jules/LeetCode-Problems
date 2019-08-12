
int reachNumber(int target) {
  if (target == 0) return 3;
  if (target < 0) target = -target;
  int sum = 0;
  int i = 0;
  while (sum < target) {
    sum += ++i;
  }
  int pad = sum - target;
  return (pad % 2 == 0) ? i : (i % 2 == 0 ? i + 1 : i + 2);
}
