#include <stack>

class Solution {
public:
    string removeDuplicates(string S) {
        std::stack<char> prev;
        std::stack<char> next;
        for (auto c = S.begin(); c != S.end(); c++) {
            prev.push(*c);
        }

        char c;
        while (!prev.empty()) {
            c = prev.top();
            if (next.empty() || next.top() != c) {
                next.push(c);
            } else {
                next.pop();
            }
            prev.pop();
        }

        std::string res;
        while(!next.empty()) {
            res.push_back(next.top());
            next.pop();
        }

        return res;
    }
};
