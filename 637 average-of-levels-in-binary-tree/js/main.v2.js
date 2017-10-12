/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */

/**
 * Leetcode最优解
 * 使用循环，替代迭代的方法
 */

function pushLeavesToArray(arr, node) {
  if (node.left) {
    arr.push(node.left)
  }
  if (node.right) {
    arr.push(node.right)
  }
  return arr
}

var averageOfLevels = function (root) {
  var results = []
  results.push(root.val)
  var nextLevel = []

  pushLeavesToArray(nextLevel, root)
  while (nextLevel.length > 0) {
    var tmpLevel = []
    var result = 0
    nextLevel.forEach(function (n) {
      tmpLevel = pushLeavesToArray(tmpLevel, n)
      result += n.val
    })
    results.push(result / nextLevel.length)
    nextLevel = tmpLevel
  }
  return results
};
