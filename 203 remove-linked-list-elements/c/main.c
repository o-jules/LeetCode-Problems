/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
  struct ListNode *p = head, *n = NULL, *prev = NULL;

  while (p) {
    if (p->val == val) {
      if (prev)
        prev->next = p->next;
    } else {
      if (n == NULL)
        n = p;

      prev = p;
    }

    p = p->next;
  }

  return n;
}
