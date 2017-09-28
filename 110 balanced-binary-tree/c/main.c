/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

#define MAX(x, y) (x > y ? x : y)

bool depth(struct TreeNode *node) {
  if (node == NULL) return 0;

  int l = depth(node->left);
  int r = depth(node->right);
  return MAX(l, r) + 1;
};

bool isBalanced(struct TreeNode* root) {
  if (root == NULL)
    return true;

  if (abs(depth(root->left) - depth(root->right)) > 1)
    return false;

  return isBalanced(root->left) && isBalanced(root->right);
}

// test
int main(void) {

  struct TreeNode r2 = {
    3, NULL, NULL
  };

  struct TreeNode r1 = {
    2, NULL, &r2
  };

  struct TreeNode r = {
    1, NULL, &r1
  };

  if (isBalanced(&r)) {
    printf("yes!");
  } else {
    printf("no!");
  }
}
