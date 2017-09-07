# Pascal三角

即 “杨辉三角”，二项式系数组成的三角。

## 失误
C++ vector 没有值之前是不是能访问的。

```cpp
vector<int> a;
a[2] = 1; // error
```

与JavaScript不同。
```js
var x = []
x[2] = 1

// x
// [<empty slot>, <empty slot>, 1]
// x.length = 3
```
