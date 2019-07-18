/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
  if (head == NULL) {
      return head;
  }
  struct ListNode* p1 = head;
  struct ListNode* p2 = head;
  int len = 0;

  while (k > 0) {
    k--;
    len++;
    if (p2->next == NULL) {
      p2 = head;
      k = k % len;
    } else {
      p2 = p2->next;
    }
  }
  while (p2->next != NULL) {
    p1 = p1->next;
    p2 = p2->next;
  }
  p2->next = head;
  p2 = p1->next;
  p1->next = NULL;

  return p2;
}
