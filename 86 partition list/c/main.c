/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *partition(struct ListNode* head, int x){
  struct ListNode *p = head, *n = NULL;
  struct ListNode *l = NULL, *r = NULL, *lh = NULL, *rh = NULL;
  while (p) {
    n = p;
    p = n->next;
    n->next = NULL;
    if (n->val < x) {
      l = l ? (l->next = n, n) : (lh = n, n);
    } else {
      r = r ? (r->next = n, n) : (rh = n, n);
    }
  }
  if (l && rh) l->next = rh;
  return lh ? lh : rh ? rh : head;
}
