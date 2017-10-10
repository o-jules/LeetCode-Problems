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
var oddEvenList = function(head) {
  if (head === null)
    return head;

  let p1 = head, t1 = head
  let h2 = head.next, p2 = null, temp = null;

  while(p1) {
    p2 = p1.next

    if (p2) {
      p1.next = p2.next
      temp = p1
      p1 = p2.next

      if (p2.next) {
        p2.next = p2.next.next
      } else {
        t1 = temp
      }
    } else {
      t1 = p1
      break
    }
  }

  t1.next = h2

  return head
};


// test
function test(n) {
  const list = make(n)

  let p = oddEvenList(list)
  let s = ''

  while (p) {
    s += '->' + p.val
    p = p.next
  }

  console.log(s)
}

function make(n) {
  let head = null, p = null
  for (let i = 1; i <= n; i++) {
    const node = {
      val: i,
      next: null
    }
    if (!head) head = node

    if (p) {
      p.next = node
      p = p.next
    } else {
      p = node
    }
  }

  return head
}

test(1)
test(2)
test(3)
test(4)
test(5)
test(6)
test(7)
test(8)
test(9)
test(10)
