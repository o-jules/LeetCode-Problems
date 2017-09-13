/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool compare(struct TreeNode *l, struct TreeNode *r) {
  return (
    (l && r && l->val == r->val &&
      compare(l->left, r->right) &&
      compare(l->right, r->left) ) ||
    (!l && !r)
  );
}

bool isSymmetric(struct TreeNode* root) {
   return !root || compare(root->left, root->right);
}
