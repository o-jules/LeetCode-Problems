#include<stdio.h>
#include<stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;

  struct ListNode *l = NULL, *t = NULL;
  if (l1->val < l2->val) {
    l = t = l1;
    l1 = l1->next;
  } else {
    l = t = l2;
    l2 = l2->next;
  }

  while (l1 && l2) {
    if (l1->val < l2->val) {
      t->next = l1;
      t = t->next;
      l1 = l1->next;
    } else {
      t->next = l2;
      t = t->next;
      l2 = l2->next;
    }
  }

  t->next = l1 ? l1 : l2;
  return l;
}




// [2], [1] => [1, 2]
int main(void) {
  struct ListNode l1 = {2, NULL};
  struct ListNode l2 = {1, NULL};

  struct ListNode *l;
  l = mergeTwoLists(&l1, &l2);
  printf("list( ");
  while (l) {
    printf("%d ", l->val);
    l = l->next;
  }
  printf(")\n");

  return 0;
}
