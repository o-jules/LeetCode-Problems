/**
 * Leetcode 最优解
 */


/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function (head, m, n) {
  // Find pre m node
  const dummyHead = {
    val: null,
    next: null
  } // new ListNode();

  dummyHead.next = head;
  let preM = dummyHead;
  for (let i = 0; i < m - 1; i++) {
    preM = preM.next;
  }

  const mHead = preM.next;
  // start reversing nodes from m to n
  let prev = null;
  let cur = mHead;
  for (let i = m; i <= n; i++) {
    const curNext = cur.next;
    cur.next = prev;
    prev = cur;
    cur = curNext;
  }

  preM.next = prev; // prev points to head of reversed m to n list
  mHead.next = cur; // mHead points to tail of reversed m to n list

  return dummyHead.next === prev ? prev : head;
};
