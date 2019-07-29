#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
      struct ListNode *next;
 };

// edge cases:
// NULL
// 1->NULL

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextLargerNodes(struct ListNode* head, int* returnSize) {
  int* greaterNodeList = NULL;
  if (!head) {
    *returnSize = 0;
    return greaterNodeList;
  }
  if (!head->next) {
    *returnSize = 1;
    greaterNodeList = (int*)malloc(sizeof(int));
    *greaterNodeList = 0;
    return greaterNodeList;
  }
  int size = 0;
  struct ListNode* p;
  p = head;
  while (p) {
    size++;
    p = p->next;
  }

  p = NULL;
  greaterNodeList = (int*)malloc(sizeof(int) * (size));
  int* p_gnl = greaterNodeList;

  struct ListNode* current = head;
  struct ListNode* prev = NULL;
  struct ListNode* lastGreater = head;

  while(current) {
    if (prev && prev->val <= current->val && lastGreater) {
      p = lastGreater;
    } else {
      p = current->next;
    }
    while (p) {
      if (p->val > current->val) {
        *p_gnl = p->val;
        p_gnl++;
        lastGreater = p;
        break;
      }
      p = p->next;
    }
    if (!p) {
      *p_gnl = 0;
      p_gnl++;
      lastGreater = NULL;
    }

    prev = current;
    current = current->next;
  }

  *returnSize = size;
  return greaterNodeList;
}



int main() {
  int count = 6;
  int list[6] = {9,7,6,7,6,9};

  struct ListNode *head = NULL;
  struct ListNode *p = NULL;
  struct ListNode *j;

  for (int i = 0; i < count; i++) {
    j = (struct ListNode *)malloc(sizeof(struct ListNode));
    j->next = NULL;
    j->val = list[i];
    if (head == NULL) {
      head = j;
      p = j;
    } else {
      p->next = j;
      p = j;
    }
  }

  int *size = (int*)malloc(sizeof(int));
  int *nln = nextLargerNodes(head, size);

  for (int i = 0; i < *size; i++) {
    printf("%d\n", (*nln));
    nln++;
  }
  // printf("size = %d\n", (*nln));
}
