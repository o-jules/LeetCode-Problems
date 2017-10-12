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
function countNodes(root) {
  if (root == null) return 0;
  if (root.left == null) return 1;

  let height = 0, nodesSum = 0;
  let p = root;
  while (p.left != null) {
    nodesSum += (1 << height);
    height++;
    p = p.left;
  }
  return nodesSum + countLastLevel(root, height);
}

function countLastLevel(root, height) {
  if (height == 1) {
    if (root.right != null)
      return 2;
    else if (root.left != null)
      return 1;
    else
      return 0;
  }

  let midNode = root.left;
  let currHeight = 1;
  while (currHeight < height) {
    currHeight++;
    midNode = midNode.right;
  }
  if (midNode == null)
    return countLastLevel(root.left, height - 1);
  else
    return (1 << (height - 1)) + countLastLevel(root.right, height - 1);
}
