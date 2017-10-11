/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function orderNode(n) {
  if (!n.next || !n.next.next) {
    return n;
  }

  const t = n.next;
  n.next = n.next.next;
  t.next = n.next.next

  return orderNode(n.next);
}

function oddEvenList(head) {
  if (!head) {
    return head;
  }

  const oddHead = head.next;
  const evenTail = orderNode(head);
  evenTail.next = oddHead;
  return head;
}
