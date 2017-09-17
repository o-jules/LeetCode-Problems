#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  if (head == NULL || n <= 0) return head;

  struct ListNode *p = head, *tprev;
  while (1) {
    n--;
    if (n == 0) tprev = head;

    if (p->next) {
      p = p->next;
      if (n < 0) tprev = tprev->next;
    } else {

      break;
    }
  }

  if (n == 0) {
    head = head->next;
  } else if (n < 0) {
    if(tprev && tprev->next) {
      tprev->next = tprev->next->next;
    }
  }

  return head;
}

// [1], 1 => []
// [1,2], 1 => [1]

void test(struct ListNode *root, int i) {
  struct ListNode *n = removeNthFromEnd(root, i);
  printf("After shift:\n");

  if (n) {
    while (n) {
      printf("%d ", n->val);
      n = n->next;
    }

    printf("\n");
  } else {
    printf("<NULL>\n");
  }
}

int main(void) {
  struct ListNode l1 = { 1, NULL };
  struct ListNode l2 = { 2, NULL };
  l1.next = &l2;
  test(&l1, 1); // [1]

  struct ListNode l3 = { 1, NULL };
  struct ListNode l4 = { 2, NULL };
  l3.next = &l4;
  test(&l3, 2); // [2]

  struct ListNode i1 = { 1, NULL };
  struct ListNode i2 = { 2, NULL };
  struct ListNode i3 = { 3, NULL };
  struct ListNode i4 = { 4, NULL };
  i1.next = &i2;
  i2.next = &i3;
  i3.next = &i4;
  test(&i1, 4); // [2]
}
