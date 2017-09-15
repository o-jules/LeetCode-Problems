#define bool int
#define true 1
#define false 0

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool identical(struct TreeNode *x, struct TreeNode *y) {
  return (
    (!x && !y) ||
    (x && y &&
      x->val == y->val &&
      identical(x->left, y->left) &&
      identical(x->right, y->right))
  );
}

void dfs(struct TreeNode* s, struct TreeNode* t, bool *isSub) {
  if (*isSub)
    return;

  if (identical(s, t)) {
    *isSub = true;
  } else {
    if (s) {
      dfs(s->left, t, isSub);
      dfs(s->right, t, isSub);
    }
  }
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
  bool isSub = false;
  dfs(s, t, &isSub);

  return isSub;
}

int main(void) {}
