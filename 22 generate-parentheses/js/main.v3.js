/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
  let g = [];
  gen(g, n, n, "");
  return g;
}


function gen (g, l, r, s){
  if (l === 0 && r === 0) {
    g.push(s)
    return
  }

  if (l > 0)
    gen(g, l - 1, r, s + '(')

  if (r > 0 && r > l)
    gen(g, l, r - 1, s + ')')
}

console.log(
  generateParenthesis(3)
)
