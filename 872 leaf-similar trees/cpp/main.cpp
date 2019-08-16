/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findLeafs(TreeNode *root, std::vector<int> &leafs) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            leafs.push_back(root->val);
        } else {
            if (root->left) {
                findLeafs(root->left, leafs);
            }
            if (root->right) {
                findLeafs(root->right, leafs);
            }
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> lf1;
        std::vector<int> lf2;

        findLeafs(root1, lf1);
        findLeafs(root2, lf2);

        return lf1 == lf2;
    }
};
