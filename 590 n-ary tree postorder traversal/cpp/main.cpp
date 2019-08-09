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
    std::vector<int> postorder(Node* root) {
        std::vector<int> list;
        if (!root) {
            return list;
        }

        std::stack<Node*> cache;
        std::stack<Node*> record;
        cache.push(root);

        while (!cache.empty()) {
            auto node = cache.top();
            if (node->children.empty()) {
                list.push_back(node->val);
                cache.pop();
                continue;
            }
            if (!record.empty()) {
                auto rec = record.top();
                if (rec == node) {
                    list.push_back(node->val);
                    cache.pop();
                    record.pop();
                    continue;
                }
            }
            record.push(node);
            for (auto child = node->children.rbegin(); child != node->children.rend(); child++) {
                cache.push(*child);
            }
        }
        return list;
    }
};
