// "x+5-3+x=6+x-2"

/**
 * @param {string} equation
 * @return {string}
 */

function lexical_parser(src) {
  let tokens = []
  let tk = ''
  const len = src.length

  for (let i = 0; i < len; i++) {
    if (src[i] === '+' || src[i] === '-') {
      tokens.push(tk)
      tk = src[i]
    } else {
      tk += src[i]
    }
  }

  if (tk.length > 0)
    tokens.push(tk)

  return tokens
}

function syntax_analyser(tks) {
  let g = [0, 0]
  for (let i = 0; i < tks.length; i++) {
    let tk = tks[i]

    if (tk.indexOf('x') > -1) {
      if (tk === 'x' || tk === '+x') {
        g[0] += 1
      } else if (tk === '-x') {
        g[0] += -1
      } else {
        let j = parseInt(tk.replace('x', ''))
        if (j) g[0] += j
      }
    } else {
      let j = parseInt(tk)
      if (j) g[1] += j
    }
  }

  return g
}

var solveEquation = function (equation) {
  const eqs = equation.split('=')
      .map(e => lexical_parser(e))
      .map(e => syntax_analyser(e))

  // console.log(eqs)
  // ax = b
  let a = eqs[0][0] - eqs[1][0]
  let b = eqs[1][1] - eqs[0][1]

  if (a == 0) {
    return b ? 'No solution': 'Infinite solutions'
  } else {
    return 'x=' + b / a
  }

};

function test(eq) {
  console.log(
    solveEquation(eq)
  )
}

test("x+5-3+x=6+x-2")
test("x=x")
test("2x=x")
test("2x+3x-6x=x+2")
test("x=x+2")
