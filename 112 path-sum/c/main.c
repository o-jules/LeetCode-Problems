
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int sum) {
  if (root == NULL)
    return false;

  sum -= root->val;
  return (root->left == NULL && root->right == NULL && sum == 0) ||
         (hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
}

// test case:
// [] 0
// [1] 1
// [1, 2] 1
