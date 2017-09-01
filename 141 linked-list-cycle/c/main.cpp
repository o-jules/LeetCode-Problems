/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * 设链表长度为n，则：
 * 时间复杂度：
 *
 * 1 + 2 + .. + n = O(n^2)
 *
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
