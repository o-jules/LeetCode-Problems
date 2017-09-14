struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

#define MAX(a, b) (a > b ? a : b)

int depthOfNode(struct TreeNode *n) {
  if (n) {
    int l = depthOfNode(n->left);
    int r = depthOfNode(n->right);
    return MAX(l, r);
  }

  return 0;
}

int diameterOfNode(struct TreeNode* n) {
  if (n) {
    return depthOfNode(n->left) + depthOfNode(n->right); // 为什么不能加上 1
  }

  return 0;
}

void maxDiamter(struct TreeNode* n, int *max) {
  if (n) {
    int d = diameterOfNode(n);
    *max = MAX(d, *max);
    maxDiamter(n->left, max);
    maxDiamter(n->right, max);
  }
}

int diameterOfBinaryTree(struct TreeNode* root) {
  int max = 0;

  if (root) {
    maxDiamter(root, &max);
  }

  return max;
}

int main(void) {
  return 0;
}
