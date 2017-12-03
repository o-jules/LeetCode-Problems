
// y = x * x

function newton(f, df) {
  return function(n) {
    // let eqn  = i => f(i) - n // equation
    let isOk = i => Math.abs(f(i) - n) <= 1e-8
    let next = i => i - (f(i) - n) / df(i)

    let x = n
    do {
      x = next(x)
    }  while (!isOk(x, n))

    return x
  }
}

var sqrt = newton(x => x * x, x => 2 * x)

function test(n) {
  console.log(sqrt(n), Math.sqrt(n))
}

test(4.0)
test(6.0)
