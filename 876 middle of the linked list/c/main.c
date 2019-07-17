#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
  if (!head) {
    return head;
  }

  struct ListNode *h = head;
  struct ListNode *p = head;
  if (h->next != NULL) {
    h = h->next;
  } else {
    return h;
  }

  while (1) {
    if (h == NULL) {
      return p;
    }
    if (h->next != NULL) {
      if (h->next != NULL) {
        h = h->next->next;
        p = p->next;
      } else {
        return p->next;
      }
    } else {
      return p->next;
    }
  }
}

int main() {
  struct ListNode *list;
  list = (struct ListNode *)malloc(sizeof(struct ListNode));
  list->val = 1;
  list->next = NULL;
  struct ListNode *tail = list;

  int count = 10;
  for (int i = 2; i <= count; i++) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = i;
    node->next = NULL;
    tail->next = node;
    tail = node;
  }

  struct ListNode *mid = middleNode(list);
  printf("%d\n", mid->val);
}
