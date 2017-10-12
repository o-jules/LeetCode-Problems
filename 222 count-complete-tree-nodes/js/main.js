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

  if (root === null)
  return 0;

  let hl = 0, hr = 0;
  let l = root, r = root;

  while(l) {
    hl++;
    l = l.left;
  }
  while(r) {
    hr++;
    r = r.right;
  }

  if(hl === hr) {
    return Math.pow(2, hl) - 1;
  }

  return 1 + countNodes(root.left) + countNodes(root.right);
}
