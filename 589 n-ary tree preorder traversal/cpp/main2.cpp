#include <vector>
#include <stack>

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    std::vector<int> preorder(Node* root) {
        std::vector<int> list;
        if (!root) {
            return list;
        }

        std::stack<Node*> cache;
        cache.push(root);
        while (!cache.empty()) {
            auto node = cache.top();
            list.push_back(node->val);
            cache.pop();

            for (auto child = node->children.rbegin(); child != node->children.rend(); child++) {
                cache.push(*child);
            }
        }
        return list;
    }
};
