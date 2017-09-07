
void invertNode(struct TreeNode *node) {
  struct TreeNode *tmp;

  if (node != NULL) {
    tmp = node->left;
    node->left = node->right;
    node->right = tmp;

    invertNode(node->left);
    invertNode(node->right);
  }
}

struct TreeNode* invertTree(struct TreeNode* root) {
  invertNode(root);
  return root;
}
