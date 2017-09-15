/**
 * Leetcode最优解
 */

bool cmpNode(struct TreeNode* s, struct TreeNode* t) {
  return (!s && !t) || (s && t && s->val == t->val);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
  return (
    (!s && !t) ||
    (
      (s && t) &&
      ((s->val == t->val &&
        cmpNode(s->left, t->left) &&
        cmpNode(s->right, t->right) &&
        isSubtree(s->left, t->left) &&
        isSubtree(s->right, t->right)) ||

        (isSubtree(s->left, t) || isSubtree(s->right, t))
      )
    )
  );
}
