'use strict';

function ListNode(val) {
  this.val = val;
  this.next = null;
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
  let list = null,
    head = null
  let remain = 0

  while (l1 !== null || l2 !== null) {
    let sum = 0
    if (l1 !== null) {
      sum += l1.val
      l1 = l1.next
    }

    if (l2 != null) {
      sum += l2.val
      l2 = l2.next
    }

    sum += remain
    if (sum >= 10) {
      remain = Math.floor(sum / 10)
      sum -= remain * 10
    } else {
      remain = 0
    }

    var newVal = new ListNode(sum)
    if (list === null) {
      list = newVal
      head = newVal
    } else {
      head.next = newVal
      head = head.next
    }
  }

  if (remain !== 0) {
    var newVal = new ListNode(remain)
    head.next = newVal
    head = head.next
  }

  return list
};
