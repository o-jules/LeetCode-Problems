/**
 * 动态分配内存
 */
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
  if (!t1) return t2;
  if (!t2) return t1;

  struct TreeNode* node = malloc(sizeof(struct TreeNode));
  node->val = t1->val+t2->val;
  node->left = mergeTrees(t1->left, t2->left);
  node->right = mergeTrees(t1->right, t2->right);
  return node;
}
