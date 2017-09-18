
void T(TreeNode *n, string p, vector<string> &path) {
  if (!n) return;

  p = p.size() ? (p + "->" + to_string(n->val)) : to_string(n->val);

  if (n->left || n->right) {
    if (n->left)  T(n->left,  p, path);
    if (n->right) T(n->right, p, path);
  } else {
    path.push_back(p);
  }
}

vector<string> binaryTreePaths(TreeNode* root) {
  vector<string> path;
  T(root, "", path); // to_string(root->val)

  return path;
}
