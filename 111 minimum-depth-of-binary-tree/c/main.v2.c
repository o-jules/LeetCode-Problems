#include <stdio.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

#define MIN(a,b) ((a) < (b) ? a : b)

void walk(struct TreeNode* n, int pmin, int *min) {
  if (pmin > *min)
    return;

  if (n->left == NULL && n->right == NULL) {
    *min = pmin;
    return;
  }

  if (n->left) walk(n->left, pmin + 1, min);
  if (n->right) walk(n->right, pmin + 1, min);
}

int minDepth(struct TreeNode* root) {
  if (root) {
    int min_depth = INT_MAX;
    walk(root, 1, &min_depth);

    return min_depth;
  }

  return 0;
}

int main(void) {

  struct TreeNode ll = {
    0,
    NULL,
    NULL,
  };
  struct TreeNode l = {
    0,
    &ll,
    NULL,
  };

  struct TreeNode rr = {
    0,
    NULL,
    NULL,
  };
  struct TreeNode r = {
    0,
    NULL,
    &rr,
  };


  struct TreeNode root = {
    0,
    &l,
    &r
  };

  printf("%d\n", minDepth(&root));
}
