
void child (TreeNode *node, int level, vector<vector<int>> &list) {
  if (node == NULL) return;

  if (level >= list.size()) {
    list.push_back(vector<int>());
  }
  list[level].push_back(node->val);

  child(node->left, level + 1, list);
  child(node->right, level + 1, list);
}

vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> list;
  child(root, 0, list);

  return list;
}
