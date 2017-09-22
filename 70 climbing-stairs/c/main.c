#include <stdio.h>

// 注意浮点精度问题的处理
int fy1(int y, int N, int fy) {
  double diff = N - 2 * y;
  double f = diff * (diff - 1.0);
  return (int) (f * fy / (y + 1.0) / (N - y)); // 把除法放在这里做，避免浮点精度不足
}

int climbStairs(int n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;

  int count = 0;
  int mid = n/2, y = 0;
  int fy = 1;

  while (y <= mid) {
    fy = y ? fy1(y - 1, n, fy) : 1;
    printf("y = %d, x = %d, fy = %d\n", y, n - 2*y, fy);
    count += fy;
    y++;
  }

  return count;
}

void test(int n) {
  printf("comb = %d\n", climbStairs(n));
}

int main(void) {
  // test(1);
  // test(2); // 3
  // test(3);
  // test(4);
  // test(5);

  test(35); // 14930352

  return 0;
}
