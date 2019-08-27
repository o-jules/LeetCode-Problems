/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode *root, int *min) {
  if (root) {
    if (min[0] == -1) {
      min[0] = root->val;
    } else {
      if (root->val < min[0]) {
        min[1] = min[0];
        min[0] = root->val;
      } else if ((min[0] != root->val) && (min[1] == -1 || root->val < min[1])) {
        min[1] = root->val;
      }
    }

    if (root->left) {
      traverse(root->left, min);
    }
    if (root->right) {
      traverse(root->right, min);
    }
  }
}

int findSecondMinimumValue(struct TreeNode* root){
    int min[2] = { -1, -1 }; // [smallest, second-smallest]
    traverse(root, min);
    if (min[0] != min[1]) {
      return min[1];
    }
    return -1;
}
