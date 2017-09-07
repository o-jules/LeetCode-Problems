
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
  return (
    (!p && !q) ||
    (p && q &&
      p->val == q->val &&
      isSameTree(p->left, q->left) &&
      isSameTree(p->right, q->right)
    )
  );
}
