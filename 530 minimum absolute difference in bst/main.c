
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfsMin(struct TreeNode* root, int *min){
    if (!root) {
        return;
    }
    if (*min == 0) {
        return;
    }

    struct TreeNode *p;
    int t;

    p = root->left;
    if (p) {
        while (p->right) {
            p = p->right;
        }
        t = root->val - p->val;
        if (t < *min) {
            *min = t;
        }
    }
    p = root->right;
    if (p) {
        while (p->left) {
            p = p->left;
        }
        t = p->val - root->val;
        if (t < *min) {
            *min = t;
        }
    }

    dfsMin(root->left, min);
    dfsMin(root->right, min);
}

int getMinimumDifference(struct TreeNode* root){
    int min = root->right ? root->right->val - root->val : root->val - root->left->val;
    dfsMin(root, &min);
    return min;
}

