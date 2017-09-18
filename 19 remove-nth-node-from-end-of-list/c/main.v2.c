/**
 * Leetcode 上的最佳解法
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  struct ListNode *p = head, *pre = head, *pre1 = head;

  while (1) {
    while (n) {
      p = p->next;
      n--;
    }

    if (p == NULL) {
      if (pre == head) {
        head = pre->next;
      } else {
        pre1->next = pre->next;
      }
      return head;
    }
    pre1 = pre;
    pre = pre->next;
    p = p->next;
  }
}
