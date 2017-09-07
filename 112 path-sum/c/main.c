
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum) {
  if (root == NULL) {
    return false;
  }

  if (root->left == NULL && root->right == NULL) {
    return sum == root->val;
  } else {
    sum -= root->val;
    if (hasPathSum(root->left, sum)) {
      return true;
    }

    if (hasPathSum(root->right, sum)) {
      return true;
    }

    return false;
  }
}

// test case:
// [] 0
// [1] 1
// [1, 2] 1
