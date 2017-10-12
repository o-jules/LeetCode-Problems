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
var countNodes = function(root) {
  if(!root) return 0;

  let height = 0;
  let left = root, right = root;
  while (right !== null) {
    left = left.left;
    right = right.right;
    height ++;
  }

  if (left === null)
    return (1 << height) - 1;

  return 1 + countNodes(root.left) + countNodes(root.right);
};
