## 为什么最优解是`1 + (num - 1) % 9`

```cpp
int addDigits(int num) {
  int res = num % 9;
  return (res != 0 || num == 0) ? res : 9;
}
```

The essence of this problem is that 10^n ≡ 1 (mod 9),
and thus a_n10^n + ... + a_110 + a_0 ≡ a_n + ... + a_1 + a_0 (mod 9).

This process can be continued until a number less than 9 is gotten, i.e. num % 9.
For any digit n, n = n % 9 unless n = 9.

The only confusing case is n % 9 = 0, but addDigits(num) = 0 if and only if num = 0, otherwise it should be 9 in fact.
