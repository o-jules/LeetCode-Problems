/**
 * 另一个解
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
  struct ListNode *prev = NULL, *p = head;

  while (p) {
    if (p->val == val) {
      if (prev) {
        prev->next = p->next;
      } else {
        head = p->next;
      }
    } else {
      prev = p;
    }

    p = p->next;
  }

  return head;
}
