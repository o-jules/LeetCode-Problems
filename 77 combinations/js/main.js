
// p：要存入的数组
// c：当前已组合好的数组
// l：当前的index
// n：总的index
// k：剩下的数量
function _combine(p, c, l, n, k) {
  if (k == 1) {
    for (let i = l + 1; i <= n; i++) {
      p.push([...c, i])
    }
  } else {
    const a = n - k + 1
    const b = k - 1
    for (let i = l + 1; i <= a; i++) {
      _combine(p, [...c, i], i, n, b)
    }
  }

}

// 从n中选择k个
function combine(n, k) {
  if (n < 0 || k < 0)  return []
  if (k == 0) return [[]]
  if (k >= n) return [new Array(n).fill(0).map((_, i) => i + 1)]

  const p = []
  _combine(p, [], 0, n, k)

  return p
}

console.log( combine(6, 0) )