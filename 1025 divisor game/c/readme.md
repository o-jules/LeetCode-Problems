# Divisor Game

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

## 分析

在可以预见的小范围内（假定为 K），任何 K % 2 == 0 的都是 True，反之为 False。

对于 N = K + 1，
若 N 为奇数，则第一步取 x 必为奇数，N - x < K 且为偶数，则 N - x 为 True，即 N 为假；
若 N 为偶数，则第一步理智地取 1，则 N - 1 < K 且为奇数，则 N - x 为 False，即 N 为真。
