/**
 * 不知道为什么不行……
 */

struct ListNode *getIntersectionNode(struct ListNode *headA,  struct ListNode *headB) {
  struct ListNode *pa = headA, *pb = headB;
  int sa = 0, sb = 0;

  while (pa != NULL && pb != NULL) {
    if (pa == pb) {
      return pa;
    }

    if (pa == NULL && !sa) {
      pa = headB;
      sa = 1;
    } else {
      if (pa)
        pa = pa->next;
    }

    if (pb == NULL || sb) {
      pb == headA;
      sb = 1;
    } else {
      if (pb)
        pb = pb->next;
    }
  }

  return NULL;
}
