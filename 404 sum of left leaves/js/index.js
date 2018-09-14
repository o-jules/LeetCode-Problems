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
var sumOfLeftLeaves = function(root) {
  if (root === null) {
    return 0;
  }
  let sum = 0;
  if (root.left !== null) {
    if (!root.left.left && !root.left.right) {
      sum += root.left.val;
    } else {
      sum += sumOfLeftLeaves(root.left);
    }
  }
  if (root.right !== null) {
      sum += sumOfLeftLeaves(root.right);
  }
  return sum;
};

// 递归解法
