function d(p, q) {
  let x = p[0] - q[0]
  let y = p[1] - q[1]
  return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2))
}

/**
 * @param {number[]} p1
 * @param {number[]} p2
 * @param {number[]} p3
 * @param {number[]} p4
 * @return {boolean}
 */

var validSquare = function(p1, p2, p3, p4) {
  let ds = [
    d(p1, p2),
    d(p1, p3),
    d(p1, p4),
    d(p2, p3),
    d(p2, p4),
    d(p3, p4)
  ].sort((l, r) => l >= r)

  return (ds[0] !== 0 &&
    (
      ds[0] === ds[1] && ds[1] === ds[2] && ds[2] === ds[3] &&
      ds[4] === ds[5]
    ))
};

function test(p1, p2, p3, p4) {
  if (validSquare(p1, p2, p3, p4)) {
    console.log("is valid")
  } else {
    console.log("not valid")
  }
}
// test:
// test([0,0], [1,1], [1,0], [0,1])
// test([1,0], [-1,0], [0,1], [0,-1])
test([4604,1524], [4574,2274], [5354,1554], [5324,2304])
