/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int *cache, int level){
  if (level > cache[0]) {
    cache[0] = level;
    cache[1] = root->val;
  }
  if (root->left) {
    dfs(root->left, cache, level + 1);
  }
  if (root->right) {
    dfs(root->right, cache, level + 1);
  }
}

int findBottomLeftValue(struct TreeNode* root){
  int val[2] = {0, root->val}; // level, value
  dfs(root, val, 0);

  return val[1];
}
