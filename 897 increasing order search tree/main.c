/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* increasingBST(struct TreeNode* root){
    if (!root) {
        return NULL;
    }

    struct Node *newRoot = root;
    if (root->left) {
        struct TreeNode *p = increasingBST(root->left);
        newRoot = p;
        while (p->right) {
            p = p->right;
        }
        p->right = root;
    }
    root->left = NULL;

    if (root->right) {
        struct TreeNode *right = increasingBST(root->right);
        root->right = right;
    }

    return newRoot;
}
