# 寻找唯一缺失的数

位运算的特性：

// XOR
a ^ a = 0
a ^ 0 = a
(a ^ b) ^ c = a ^ (b ^ c)

对于缺失某个数的数组 0, 1, 2, ..., n,（其最大数肯定不会缺失），
其长度是 n（若不缺失，则长度是 n + 1），其索引值为 0, 1, ..., n - 1。

所以将数组中的结果及相关的index都使用^运算，设初始数为s，缺失的数为i，则最终的结果为：

s^i^n

（需要注意的是，初始值 s 不能是可能缺失的某个数）。

由于n不会缺失，可以使用 n 作初始值。

此时 s^i^n = i。
