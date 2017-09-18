
#define MAX(l, r) (l > r ? l : r)

int maxDepth(struct TreeNode* root) {
  if(root) {
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + MAX(l, r);
  }

  return 0;
}
