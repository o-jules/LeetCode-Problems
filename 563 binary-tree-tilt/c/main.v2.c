/**
 * DFS
 */
int dfs (struct TreeNode *root, int *tilt)
{
    int lsum, rsum;

    if (!root) {
        return (0);
    }

    lsum = dfs(root->left, tilt);
    rsum = dfs(root->right, tilt);
    *tilt += abs(lsum-rsum);

    return (lsum+rsum+root->val);
}

int findTilt (struct TreeNode *root)
{
    int tilt = 0;

    dfs(root, &tilt);

    return (tilt);
}
