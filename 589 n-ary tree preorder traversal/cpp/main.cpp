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
    vector<int> preorder(Node* root) {
        vector<int> list;
        if (!root) {
            return list;
        }
        list.push_back(root->val);

        auto children = root->children;
        for (auto child = children.begin(); child != children.end(); child++) {
            auto child_list = preorder(*child);
            for(auto val = child_list.begin(); val != child_list.end(); val++) {
                list.push_back(*val);
            }
        }
        return list;
    }
};
