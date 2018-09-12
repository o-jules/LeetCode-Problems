/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function(root, val) {
  if (root === null) {
    return [];
  }
  if (root.val === val) {
    return root;
  } else if (root.val < val) {
    return searchBST(root.right, val);
  } else {
    return searchBST(root.left, val);
  }
};

console.log(
  searchBST({
    val: 4,
    left: {
      val: 2,
      left: {
        val: 1, left: null, right: null,
      },
      right: {
        val: 3, left: null, right: null,
      }
    },
    right: {
      val: 7, left: null, right: null
    }
  }, 2)
)
