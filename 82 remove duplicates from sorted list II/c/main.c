/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
  struct ListNode *p = NULL;
  struct ListNode *cur = head;

  int curIsDepl = 0;
  // find the first one
  while (!p && cur) {
    if (cur->next) {
      if (cur->val != cur->next->val) {
        if (curIsDepl == 0) {
          p = cur;
        } else {
          curIsDepl = 0;
        }
      } else {
        curIsDepl = 1;
      }
    } else {
      if (curIsDepl == 0) {
        p = cur;
      }
    }
    cur = cur->next;
  }
  if (!p) {
    return p;
  }

  struct ListNode* newHead = p;
  curIsDepl = 0;
  while (cur) {
    if (cur && cur->next) {
      if (cur->val != cur->next->val) {
        if (curIsDepl) {
          //
        } else {
          p->next = cur;
          p = p->next;
        }
        curIsDepl = 0;
      } else {
        curIsDepl = 1;
      }
    } else {
      if (curIsDepl) {
        p->next = NULL;
      } else {
        p->next = cur;
      }
    }
    cur = cur->next;
  }
  return newHead;
}


