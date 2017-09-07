
void invertNode(struct TreeNode *node) {
  if (node != NULL) {
    struct TreeNode *tmp;

    tmp = node->left;
    node->left = node->right;
    node->right = tmp;

    invertNode(left);
    invertNode(right);
  }
}

struct TreeNode* invertTree(struct TreeNode* root) {
  invertNode(root);
}
