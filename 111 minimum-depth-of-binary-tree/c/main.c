/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MIN(a,b) ((a) < (b) ? a : b)

int minDepth(struct TreeNode* root) {

  if (root) {
    int l = minDepth(root->left);
    int r = minDepth(root->right);

    if (r == 0) {
      return l + 1;
    } else if (l == 0) {
      return r + 1;
    } else {
      return MIN(l, r) + 1;
    }

  }

  return 0;
}
