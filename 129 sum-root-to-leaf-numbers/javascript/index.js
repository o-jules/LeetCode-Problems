/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumNumbers = function(root) {
  let sum = 0

  function sumPath(current, node) {
    if (!node) {
      sum += parseInt(current)
    } else {
      if (!node.left && !node.right) {
        sum += parseInt(current + node.val)
      } else {
        if (node.left) {
          sumPath(current + node.val, node.left)
        }
        if (node.right) {
          sumPath(current + node.val, node.right)
        }
      }
    }
  }

  sumPath("0", root)

  return sum
};

console.log(sumNumbers({
  val: 1,
  left: {
    val: 2
  },
  right: {
    val: 3
  }
}))
