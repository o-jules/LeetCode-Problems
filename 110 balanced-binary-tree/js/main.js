
function depth(node) {
  if (node == null) return 0;

  let l = depth(node.left);
  let r = depth(node.right);
  return Math.max(l, r) + 1;
};

function isBalanced(root) {
  if (root == null)
    return true;

  if (Math.abs(depth(root.left) - depth(root.right)) > 1)
    return false;

  return isBalanced(root.left) && isBalanced(root.right);
}

if (isBalanced({
  val: 1,
  left: null,
  right: {
    val: 2,
    left: null,
    right: {
      val: 3,
      left: null,
      right: null
    }
  }
})) {
  console.log("yes!")
} else {
  console.log("no!")
}
