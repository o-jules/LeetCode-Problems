
function generateParenthesis(n) {
  const res = []
  gen(res, '', n, 0)
  return res
}

function gen (v, s, n, m) {
  if(n === 0 && m === 0) {
    v.push(s)
    return
  }

  if(m > 0) gen(v, s + ')', n,     m - 1)
  if(n > 0) gen(v, s + '(', n - 1, m + 1)
}

console.log(
  generateParenthesis(3)
)
