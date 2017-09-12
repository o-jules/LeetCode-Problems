#define NULL 0

struct ListNode {
  int val;
  struct ListNode *next;
};

// [1], []

struct ListNode *getIntersectionNode(struct ListNode *headA,  struct ListNode *headB) {
  struct ListNode *pa = headA, *pb = headB;
  while (pa != pb) {
    pa = pa ? pa->next: headB;
    pb = pb ? pb->next: headA;
  }

  return pa;
}

// test case:
// [],     []
// [],     [1, 2, 3, 4]
// [1],    [2, 3, 4, 5]
// [1, 3], []
// [1],    []

int main(void) {
  return 0;
}
