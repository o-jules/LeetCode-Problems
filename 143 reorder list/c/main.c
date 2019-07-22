#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
     int val;
     struct ListNode *next;
 };

void reorderList(struct ListNode* head) {
  if (!head || !head->next) {
    return;
  }

  // find middle node
  struct ListNode *i, *j, *k;
  i = head;
  j = NULL;
  while(i) {
    i = i->next;
    j = j ? j->next : head;
    if (i) {
      i = i->next;
    }
  }
  i = j;
  j = j->next;
  i->next = NULL;
  // now `j` is the middle

  // reverse the final half list
  k = j->next;
  j->next = NULL;
  while (k) {
    i = k->next;
    k->next = j;
    j = k;
    k = i;
  }
  // now `j` is the tail

  k = head;
  while (j != NULL && k != NULL) {
    i = k->next;
    k->next = j;
    j = i;
    k = k->next;
  }

}

int main() {
  struct ListNode *list;
  list = (struct ListNode *)malloc(sizeof(struct ListNode));
  list->val = 1;
  list->next = NULL;
  struct ListNode *tail = list;

  int count = 2;
  for (int i = 2; i <= count; i++) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = i;
    node->next = NULL;
    tail->next = node;
    tail = node;
  }

  struct ListNode *p = list;
  printf("before:\n");
  while (p != NULL) {
    printf("%d\n", p->val);
    p = p->next;
  }

  reorderList(list);

  p = list;
  printf("after:\n");
  while (p != NULL) {
    printf("%d\n", p->val);
    p = p->next;
  }
}
