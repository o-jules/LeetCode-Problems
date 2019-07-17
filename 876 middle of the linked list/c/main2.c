
struct ListNode* middleNode(struct ListNode* head) {
  if (!head) {
    return head;
  }

  struct ListNode *h = head;
  struct ListNode *p = head;
  unsigned char is_double = 0;
  while(h != NULL) {
    h = h->next;
    if (is_double == 1) {
      p = p->next;
      is_double = 0;
    } else {
      is_double = 1;
    }
  }
  return p;
}
