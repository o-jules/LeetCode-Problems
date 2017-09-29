/**
 *
 * @param {number} n
 * @return Array<String>
 */
function generateParenthesis(n) {
  const g = [] // Array<string>
  if (n > 0) {
    // g ^= 0
    gen(g, '', n, n)
  }

  return g
}

function gen(g, c, l, r) {
  if (c && c[0] === ')')
    return

  if (l == 0 && r == 0) {
    if (valid(c)) g.push(c)
    return
  }

  if (l > 0) gen(g, c + '(', l - 1, r)
  if (r > 0) gen(g, c + ')', l, r - 1)
}

function valid(s) {
  const stack = []
  let i = 0, len = s.length
  for (; i < len; i++) {
    if (s[i] == ')') {
      if (stack[stack.length - 1] !== '(')
        return false
      else
        stack.pop(')')
    } else {
      stack.push('(')
    }
  }

  return (stack.length === 0)
}

console.log(
  generateParenthesis(3)
)
