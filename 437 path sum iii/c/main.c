#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void pathSumSearch(struct TreeNode* root, int sum, int *count, int visited) {
    if (root) {
        if (!visited && root->left) {
            pathSumSearch(root->left, SUM, SUM, count, 0);
        }
        if (!visited && root->right) {
            pathSumSearch(root->right, SUM, SUM, count, 0);
        }

        sum -= root->val;
        if (sum == 0) {
            *count += 1;
        }
        if (root->left) {
            pathSumSearch(root->left, SUM, sum, count, 1);
        }
        if (root->right) {
            pathSumSearch(root->right, SUM, sum, count, 1);
        }
    }
    return 0;
}

int pathSum(struct TreeNode* root, int sum){
    int *count = malloc(sizeof(int));
    *count = 0;
    pathSumSearch(root, sum, sum, count, 0);

    int c = *count;
    free(count);
    return c;
}
