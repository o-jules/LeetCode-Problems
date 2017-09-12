
struct ListNode* deleteDuplicates(struct ListNode* head) {
  struct ListNode* p = head;

  while (p) {
    if (p->next && p->next->val == p->val) {
      p->next = p->next->next;
    } else {
      p = p->next;
    }
  };

  return head;
}
