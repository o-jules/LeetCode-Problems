function valOf(node) {
  return node !== null ? node.val : 0
}

function addTwoNumbers(l1, l2) {
  let list = new ListNode(0), head = list
  let p = l1, q = l2
  let carry = 0

  while (p !== null || q !== null) {
    let sum = valOf(p) + valOf(q) + carry
    carry = Math.floor(sum / 10)
    sum -= carry * 10

    head.next = new ListNode(sum)
    head = head.next
    if (p !== null) p = p.next
    if (q !== null) q = q.next
  }

  if (carry > 0) {
    head.next = new ListNode(carry)
  }

  return list.next
};
