/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} t
 * @return {string}
 */
var tree2str = function(t, notRoot) {
  if (t == null)
    return ''

  let s = ''
  s += t.val
  if (t.left || t.right) {
    const l = tree2str(t.left, true)
    const r = tree2str(t.right, true)
    s += (l === '' ? '()': l) + r
  }

  if (notRoot) s = '(' + s + ')'
  return s
};



// test
console.log(tree2str({
  val: 1,
  left: {
    val: 2,
    left: {
      val: 4,
      left: null,
      right: null
    },
    right: null
  },
  right: {
    val: 3,
    left: null,
    right: null
  }
}))

console.log(tree2str(null))

console.log(tree2str({
  val: 1,
  left: {
    val: 2,
    left: null,
    right: {
      val: 4,
      left: null,
      right: null
    }
  },
  right: {
    val: 3,
    left: null,
    right: null
  }
}))
