static int max_;

int max(int a, int b) {
    return a > b ? a : b;
}

int depth(struct TreeNode *root) {
    if(!root)
        return 0;
    int left = depth(root->left), right = depth(root->right);
    max_ = max(max_, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    if(!root)
        return 0;
    max_ = 0;
    depth(root);
    return max_;
}
