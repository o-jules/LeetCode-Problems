#include <stack>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
  Node* flatten(Node* head) {
    Node* p = head;
    Node* t = NULL;
    std::stack<Node*> cache = {};

    while (p) {
      if (p->child) {
        if (p->next) {
          cache.push(p->next);
        }
        t = p->child;
        t->prev = p;
        p->next = t;
        p->child = NULL;
        p = t;
      } else {
        if (p->next) {
          p = p->next;
        } else {
          if (cache.empty()) {
            p = NULL;
          } else {
            t = cache.top();
            p->next = t;
            t->prev = p;
            p = p->next;
            cache.pop();
          }
        }
      }
    }
    return head;
  }
};
