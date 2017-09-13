#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

struct ListNode {
  int val;
  struct ListNode *next;
};

bool isPalindrome(struct ListNode *head) {
  if (head == NULL)
    return true;

  int c = 0;
  struct ListNode *lp = head, *rp;
  while (lp) {
    lp = lp->next;
    c++;
  }
  if (c == 1) return true;

  lp = head;
  int l = c/2 - 1;
  while (l--) lp = lp->next;
  rp = c%2? lp->next->next: lp->next;

  // reverse left list
  struct ListNode *p = head;
  struct ListNode *n = head->next;
  struct ListNode *nn;
  p->next = NULL;
  while (p != lp)
  {
    nn = n->next;
    n->next = p;
    p = n;
    n = nn;
  }

  while (lp != NULL && rp != NULL) {
    if (lp->val != rp->val) {
      return false;
    }
    lp = lp->next;
    rp = rp->next;
  }

  return true;
}

struct ListNode *makeList(int len) {
  if (len <= 0) {
    return NULL;
  } else {
    int i = 0;
    struct ListNode l = { -1, NULL };
    struct ListNode *p = &l;
    while (i < len) {
      struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
      n->val = i;
      n->next = NULL;

      p->next = n;
      p = p->next;
      i++;
    }
    return l.next;
  }
}

void printList(struct ListNode *l) {
  struct ListNode *p = l;

  printf("(");
  while (p != NULL) {
    printf("%d", p->val);
    p = p->next;
    if (p != NULL)
      printf("-");
  }
  printf(")");
  printf("\n");
}

int main(void) {

  if (isPalindrome(NULL)) {
    printf("Is Pa\n");
  } else {
    printf("No Pa\n");
  }

  struct ListNode *list = makeList(4);
  printList(list);
  if (isPalindrome(list)) {
    printf("Is Pa\n");
  } else {
    printf("No Pa\n");
  }

  list = makeList(4);
  list->next->next->val = 1;
  list->next->next->next->val = 0;

  printList(list);
  if (isPalindrome(list)) {
    printf("Is Pa\n");
  } else {
    printf("No Pa\n");
  }

  list = makeList(3);
  list->val = 2;
  printList(list);
  if (isPalindrome(list)) {
    printf("Is Pa\n");
  } else {
    printf("No Pa\n");
  }
}
