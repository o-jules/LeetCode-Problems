/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
  if (head == NULL || head->next == NULL)
    return false;

  struct ListNode *p = head;
  struct ListNode *t;

  while(true) {
    if (p->next == p) {
      return true;
    }

    t = head;
    while(t != p) {
      if (p->next == t) {
        return true;
      } else {
        t = t->next;
      }
    }

    if (p->next != NULL) {
      p = p->next;
    } else {
      break;
    }
  }

  return false;
}
