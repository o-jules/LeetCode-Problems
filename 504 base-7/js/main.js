
var convertToBase7 = function(num) {
  if (num === 0)
    return '0'

  let res = ''
  let neg = num < 0
  if (neg) num = -num
  num ^= 0

  while (num) {
    res = num%7 + res
    num = Math.floor(num/7)
  }

  if (neg)
    res = '-' + res

  return res
};

function test(n) {
  console.log(
    convertToBase7(n)
  )
}

test(0)
test(10)
test(-7)
test(27)
