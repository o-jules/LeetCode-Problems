# 要点

两个字符串所含的字符要完全一样：

  - 空字符串；
  - 诸如 woo, owl 的对，前者的所有字母都在后者中，但两者不相等；

## 最优解

Leetcode上的最优解是利用每个字符对应成质数，再其乘积作为单词的唯一签名。但该方法不具有普适性（如字母不是简单的拉丁字母，或者单词很长等）。

次优解将字符排序，再将排序后的结果利用unordered_map作为验证。
