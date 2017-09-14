#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDepth(struct TreeNode *root, int* maxDiameter) {
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left, maxDiameter);
    int right = maxDepth(root->right, maxDiameter);
    *maxDiameter = MAX(*maxDiameter, left + right);

    return 1 + MAX(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int maxDiameter = 0;
    maxDepth(root, &maxDiameter);

    return maxDiameter;
}
