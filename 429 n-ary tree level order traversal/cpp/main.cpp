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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        vector<Node*> rec1 = { root };
        vector<Node*> rec2;
        vector<Node*> *current = &rec1;
        vector<Node*> *next = &rec2;
        vector<Node*> *temp;

        while (!current->empty()) {
            vector<int> current_level;
            for (auto n = current->begin(); n != current->end(); n++) {
                current_level.push_back((*n)->val);
                next->insert(next->end(), (*n)->children.begin(), (*n)->children.end());
            }
            result.push_back(current_level);

            temp = current;
            current = next;
            next = temp;
            next->clear();
        }

        current->clear();
        next->clear();
        return result;
    }
};
