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

void reorderList(struct ListNode* head){
  if (head == NULL || head->next == NULL) {
    return;
  }

  // find middle node
  struct ListNode *i = head;
  struct ListNode *p = NULL;
  unsigned char is_double = 0;
  while(i != NULL) {
    i = i->next;
    if (is_double == 1) {
      p = p == NULL ? head: p->next;
      is_double = 0;
    } else {
      is_double = 1;
    }
  }
  i = p;
  p = p->next;
  i->next = NULL;
  // now `p` is the middle

  // reverse the final half list
  struct ListNode *t = p;
  struct ListNode *n = p->next;
  t->next = NULL;
  while (n)
  {
    i = n->next;
    n->next = t;
    t = n;
    n = i;
  }
  // now t is the tail

  unsigned char is_first_half = 1;
  struct ListNode *first_half_head = head;
  struct ListNode *second_half_head = t;
  i = head;
  while (first_half_head != NULL && second_half_head != NULL) {
    if (is_first_half == 1) {
      first_half_head = first_half_head->next;
      i->next = second_half_head;
      i = i->next;
      is_first_half = 0;
    } else {
      second_half_head = second_half_head->next;
      i->next = first_half_head;
      i = i->next;
      is_first_half = 1;
    }
  }

}

int main() {
  struct ListNode *list;
  list = (struct ListNode *)malloc(sizeof(struct ListNode));
  list->val = 1;
  list->next = NULL;
  struct ListNode *tail = list;

  int count = 4;
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
