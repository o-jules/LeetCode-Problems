#define VAL(n) (n? n->val : 0)

int sum(struct TreeNode* n) {
  return n ? n->val + sum(n->left) + sum(n->right): 0;
}

int findTilt(struct TreeNode* root) {
  int tilt = 0;
  if (root) {
    tilt = abs(sum(root->left) - sum(root->right)) + findTilt(root->left) + findTilt(root->right);
  }
  return tilt;
}
