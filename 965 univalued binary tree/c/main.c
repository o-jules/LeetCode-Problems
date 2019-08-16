/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isUnival(struct TreeNode* root, int val){
    if (!root) return true;
    if (root->val != val) return false;

    return isUnival(root->left, val) && isUnival(root->right, val);
}

bool isUnivalTree(struct TreeNode* root){
    return isUnival(root->left, root->val) && isUnival(root->right, root->val);
}
