/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head) {
  if (head == NULL) return NULL;

  struct ListNode *p = head;
  struct ListNode *n = head->next;
  struct ListNode *nn;
  p->next = NULL;
  while (n)
  {
    nn = n->next;
    n->next = p;
    p = n;
    n = nn;
  }

  return p;
}
