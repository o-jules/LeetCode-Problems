# 爬梯问题

已知梯子里程为 N 步，一次能行走 1步 或 2步，求所有走法的组合。

## 分析1：

对于 N 步，可由 x 个 1 步 和 y 个2 步组成，求所有可能的 (x, y) 有序对构成的的组合的总数即可。

若已知 y， 由 x + 2y = N，得 x = N - 2y，则其不同排序的可能性为：

g(y) = (x+y)! / (x!y!) = (N - 2y + y)! / ((N - 2y)! y!)

由于 y 的取值范围是(0, N/2)，所以结果是：

$$$
f(N) = \sum_{N/2}^{i = 0} g(i)
$$$

**计算的优化**

g(0) = N!/N! = 1

g(y + 1) = g(y) * (N - 2y)(N - 2y + 1)/ ((y + 1)(N - y))

**伪代码**

```c
int gy1(int y, int gy, int N) {
  return gy * (N - 2 * y) * (N - 2 * y + 1) / (y + 1) / (N - y);
}

int f(int n) {
  int mid = n/2, y = 0;
  int count = 0;
  int fy = 0;
  while (y <= mid) {
    gy = y ? gy1(y - 1, gy, n) : 1;

    count += gy;
    y++;
  }

  return count;
}
```

## 分析2

对于N，

N = 1, f(N) = 1
N = 2, f(N) = 2
N > 2, f(N) = f(N - 1) + f(N - 2)

(即对于完成N，最后一步有两个可能： 1. 完成 N - 1 步后，进 1 步； 2. 完成 N - 2 步后，进 2 步)

### Fibbonaci 函数

$$
F_n = 1 / \sqrt{5} \(\(\frac{1+\sqrt{5}}{2}\)^{n+1} - \(\frac{1 - \sqrt{5}}{2}\)^{n+1}\)
$$
