
var averageOfLevels = function(root) {
  let avg = []
  let i = 0, c = 0

  if (root) {
    calc(root, avg, 0)
  }

  return avg.map(e => e.val / e.count)
};

function calc(root, avg, level) {
  if (root === null)
    return;

  if (avg[level]) {
    avg[level].val += root.val
    avg[level].count++
  } else {
    avg[level] = {
      val: root.val,
      count: 1
    }
  }
  level++
  calc(root.left, avg, level)
  calc(root.right, avg, level)
}

function test(tree) {
  console.log(averageOfLevels(tree))
}

test({
  val: 3,
  left: {
    val: 9,
    left: null, right: null
  },
  right: {
    val: 20,
    left: {
      val: 15,
      left: null, right: null
    },
    right: {
      val: 7,
      left: null, right: null
    }
  }
})
