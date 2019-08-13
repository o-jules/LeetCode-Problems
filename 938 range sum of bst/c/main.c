/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode* root, int L, int R, int *ans) {
    if (root) {
        if (root->val >= L && root->val <= R) {
            *ans += root->val;
        }
        if (root->val >= L) {
            traverse(root->left, L, R, ans);
        }
        if (root->val <= R) {
            traverse(root->right, L, R, ans);
        }
    }
}

int rangeSumBST(struct TreeNode* root, int L, int R){
    if (!root) {
        return 0;
    }

    int sum = 0;
    traverse(root, L, R, &sum);
    return sum;
}

